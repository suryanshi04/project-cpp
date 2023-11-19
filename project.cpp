#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Music {
    std::string title;
    std::string artist;

    Music(const std::string& _title, const std::string& _artist) : title(_title), artist(_artist) {}
};

class Playlist {
public:
    std::string name;
    std::vector<Music> songs;

    Playlist(const std::string& _name) : name(_name) {}

    void addMusic(const Music& music) {
        songs.push_back(music);
    }

    void removeMusic(const std::string& title) {
        songs.erase(std::remove_if(songs.begin(), songs.end(),
            [title](const Music& music) { return music.title == title; }
        ), songs.end());
    }
};

class MusicManager {
public:
    std::vector<Playlist> playlists;

    Playlist& createPlaylist(const std::string& name) {
        playlists.emplace_back(name);
        return playlists.back();
    }

    void listPlaylists() {
        for (const Playlist& playlist : playlists) {
            std::cout << "Playlist: " << playlist.name << "\n";
        }
    }

    void createFolder(const std::string& folderName) {
        // Create a folder logic here
        std::cout << "Folder '" << folderName << "' created.\n";
    }

    void sortPlaylists() {
        std::sort(playlists.begin(), playlists.end(), [](const Playlist& a, const Playlist& b) {
            return a.name < b.name;
        });
    }
};

int main() {
    MusicManager musicManager;

    while (true) {
        int choice;
        std::cout << "\nMenu:\n";
        std::cout << "1. Create Playlist\n";
        std::cout << "2. List Playlists\n";
        std::cout << "3. Create Folder\n";
        std::cout << "4. Sort Playlists\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            std::cout << "Enter playlist name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            musicManager.createPlaylist(name);
            std::cout << "Playlist created.\n";
        } else if (choice == 2) {
            musicManager.listPlaylists();
        } else if (choice == 3) {
            std::string folderName;
            std::cout << "Enter folder name: ";
            std::cin.ignore();
            std::getline(std::cin, folderName);
            musicManager.createFolder(folderName);
        } else if (choice == 4) {
            musicManager.sortPlaylists();
            std::cout << "Playlists sorted alphabetically.\n";
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
