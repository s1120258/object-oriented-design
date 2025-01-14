#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <string>
#include <deque>
#include <chrono>
#include <thread>
#include <atomic>

class Playlist {
public:
	Playlist();

	void add(const Song& song);
	void insert(int index, const Song& song);
	void remove(int index);

	void play();
	void pause();
	void next();
	void clear();

	void display() const;
	bool isSongFinished() const;
	void resetSongFinished();

private:
	void startTimer();
	void stopTimer();
	void clearTimer();
	void playback();

	std::deque<Song> songs;

	bool isPlaying;
	bool isPaused;
	int currentDuration;

	std::chrono::time_point<std::chrono::steady_clock> startTime;
	std::thread playbackThread;
	std::atomic<bool> stopFlag;
	std::atomic<bool> songFinished;
};

#endif // PLAYLIST_H
