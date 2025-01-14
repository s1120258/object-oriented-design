#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Playlist.h"
#include <atomic>

class Jukebox
{
public:
	Jukebox();

	void addSongToPlaylist(const Song& song);
	void insertSongToNext(const Song& song);
	void removeSongFromPlaylist(int index);

	void play();
	void pause();
	void next();
	void clear();

	void display() const;
	bool isSongFinished() const;
	void resetSongFinished();
	void setSongFinished();

private:
	Playlist playlist;
	std::atomic<bool> songFinishedFlag;
};

#endif // JUKEBOX_H
