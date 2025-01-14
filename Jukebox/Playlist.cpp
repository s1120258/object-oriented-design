#include "Playlist.h"
#include <iostream>

Playlist::Playlist() : isPlaying(false), isPaused(false), currentDuration(0), stopFlag(false), songFinished(false) {}

void Playlist::add(const Song& song) {
    songs.push_back(song);
}

void Playlist::insert(int index, const Song& song) {
    songs.insert(songs.begin() + index, song);
}

void Playlist::remove(int index) {
    songs.erase(songs.begin() + index);
}

void Playlist::play() {
    if (songs.empty()) {
        std::cout << "No songs in the playlist.\n";
        return;
    }
    if (isPlaying && !isPaused) {
        std::cout << "Already playing. Use next/previous to navigate.\n";
        return;
    }
    std::cout << "Starting to play...\n";
    isPlaying = true;
    isPaused = false;
    stopFlag = false;
    songFinished = false;
    if (playbackThread.joinable()) {
        playbackThread.join();
    }
    playbackThread = std::thread(&Playlist::playback, this);
}

void Playlist::pause() {
    if (!isPlaying || isPaused) {
        std::cout << "No song is currently playing or already paused.\n";
        return;
    }
    std::cout << "Pausing the current song.\n";
    isPaused = true;
    stopFlag = true;
    if (playbackThread.joinable()) {
        playbackThread.join();
    }
    stopTimer();
}

void Playlist::next() {
    if (songs.empty() || songs.size() < 2) {
        std::cout << "No next songs in the playlist.\n";
        return;
    }
    if (isPlaying) {
        stopFlag = true;
        if (playbackThread.joinable()) {
            playbackThread.join();
        }
    }
    songs.pop_front();
    if (songs.empty()) {
        std::cout << "No more songs in the playlist.\n";
        isPlaying = false;
        isPaused = false;
        return;
    }
    isPlaying = true;
    clearTimer();
    play();
}

void Playlist::clear() {
    if (isPlaying) {
        stopFlag = true;
        if (playbackThread.joinable()) {
            playbackThread.join();
        }
    }
    songs.clear();
    isPlaying = false;
    isPaused = false;
}

void Playlist::display() const {
    if (songs.empty()) {
        std::cout << "No songs in the playlist.\n";
		return;
    }

    std::cout << "Current Song:" << std::endl;
    songs.front().displayInfo();

    std::cout << "Playlist:" << std::endl;
    for (size_t i = 0; i < songs.size(); i++) {
        std::cout << i + 1 << ". ";
        songs[i].displayInfo();
    }
}

void Playlist::startTimer() {
    if (!isPlaying || isPaused || songs.empty()) {
        return;
    }
    startTime = std::chrono::steady_clock::now();
}

void Playlist::stopTimer() {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    currentDuration += static_cast<int>(elapsed);
    std::cout << "Song paused at " << currentDuration << " seconds.\n";
}

void Playlist::clearTimer() {
    currentDuration = 0;
}

void Playlist::playback() {
    int duration = songs.front().getDuration();
    startTimer();
    for (int i = currentDuration; i < duration; ++i) {
        if (stopFlag) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate 1 second passing
        std::cout << "Time left: " << duration - (i + 1) << " seconds...\r";
    }
    if (!stopFlag) {
        std::cout << "\nSong finished.\n";
        songFinished = true;
    }
}

bool Playlist::isSongFinished() const {
    return songFinished;
}

void Playlist::resetSongFinished() {
    songFinished = false;
}
