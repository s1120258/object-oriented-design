#include "Jukebox.h"
#include "Song.h"

Jukebox::Jukebox() {}

void Jukebox::addSongToPlaylist(const Song& song) {
	playlist.add(song);
}

void Jukebox::insertSongToNext(const Song& song) {
	playlist.insert(1, song);
}

void Jukebox::removeSongFromPlaylist(int index) {
	playlist.remove(index);
}

void Jukebox::play() {
	playlist.play();
}

void Jukebox::pause() {
	playlist.pause();
}

void Jukebox::next() {
	playlist.next();
}

void Jukebox::clear() {
	playlist.clear();
}

void Jukebox::display() const {
	playlist.display();
}

bool Jukebox::isSongFinished() const {
	return songFinishedFlag.load();
}

void Jukebox::resetSongFinished() {
	songFinishedFlag.store(false);
}

void Jukebox::setSongFinished() {
	songFinishedFlag.store(true);
}
