#include <Timer.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>

// Constructor
Timer::Timer(double t) : time(t * 60) {}

// Function to play audio
void playAudio(const std::string& relativePath) {
    // Resolve the absolute path using std::filesystem
    std::string fullPath = std::filesystem::absolute(relativePath).string();

    // Load the audio file into a music player (sf::Music is better for longer files)
    sf::Music music;
    if (!music.openFromFile(fullPath)) {
        std::cerr << "Failed to load audio file: " << fullPath << std::endl;
        return;
    }

    // Play the music
    music.play();

    // Keep the program alive while the music is playing
    while (music.getStatus() == sf::Music::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}

// Timer function
void Timer::printTimer()
{
    bool run = true;
    bool prompt = true;
    int i = 0;
    int log{};
    playAudio("go.mp3");
    while (run) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i++;
        log++;
        std::cout << "\rIt has been " << i << " seconds. " << std::flush;

        if (i == 10) { // Replace with `if (i == 1500)` for 25 minutes
            // Play audio notification (relative to `src`)
            playAudio("ending.mp3");

            // Prompt user
            std::cout << "\nIt has been 25 minutes, would you like to take a break? ENTER 0<quit>/1<take a break>: ";
            std::cin >> prompt;
        }

        if (!prompt) {
            run = false;
            std::cout << "Have a good day! " << std::endl;
        }
    }
}
