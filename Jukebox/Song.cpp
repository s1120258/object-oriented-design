#include "Song.h"
#include <string>
#include <iostream>

Song::Song(std::string title, std::string artist, int duration) : title(title), artist(artist), duration(duration) {}

std::string Song::getTitle() const {
	return title;
}

void Song::setTitle(const std::string& title) {
	this->title = title;
}

std::string Song::getArtist() const {
	return artist;
}

void Song::setArtist(const std::string& artist) {
	this->artist = artist;
}

int Song::getDuration() const {
	return duration;
}

void Song::setDuration(int duration) {
	this->duration = duration;
}

void Song::displayInfo() const {
	std::cout << "Song: " << title << " by " << artist << " [" << duration << "s]" << std::endl;
}
