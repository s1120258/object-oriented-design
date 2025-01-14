#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
public:
	Song(std::string title, std::string artist, int duration);

	std::string getTitle() const;
	void setTitle(const std::string& title);

	std::string getArtist() const;
	void setArtist(const std::string& artist);

	int getDuration() const;
	void setDuration(int duration);

	void displayInfo() const;

private:
	std::string title;
	std::string artist;
	int duration;// Duration in seconds
};

#endif // SONG_H