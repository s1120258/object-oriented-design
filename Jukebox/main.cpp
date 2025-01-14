#include "Jukebox.h"
#include "Song.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // Create a jukebox instance
    Jukebox jukebox;

    // Adding songs to the jukebox
    jukebox.addSongToPlaylist(Song("Song 1", "Artist A", 5));
    jukebox.addSongToPlaylist(Song("Song 2", "Artist B", 10));
    jukebox.addSongToPlaylist(Song("Song 3", "Artist C", 8));

    int choice;

    while (true) {
        // Menu for user interaction
        std::cout << "\n--- Jukebox Menu ---\n";
        std::cout << "1. Play\n";
        std::cout << "2. Pause\n";
        std::cout << "3. Next\n";
        std::cout << "4. Clear\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            jukebox.play();
            break;
        case 2:
            jukebox.pause();
            break;
        case 3:
            jukebox.next();
            break;
        case 4:
            jukebox.clear();
            break;
        case 0:
            std::cout << "Exiting Jukebox.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }

        jukebox.display();
    }

    return 0;
}