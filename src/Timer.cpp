#include <Timer.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>

// Constructor
Timer::Timer(double t) : time(t * 60) {}

void playAudio(const std::string& relativePath)
{
    std::string fullPath = std::filesystem::absolute(relativePath).string();
    sf::Music music;
    if (!music.openFromFile(fullPath))
    {
        std::cerr << "Failed to load audio file: " << fullPath << std::endl;
        return;
    }
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
    int i = 0;
    int log{};
    playAudio("go.mp3");
    while (run) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i++;
        log++;
        std::cout << "\rIt has been " << i << " seconds. " << std::flush;

        if (i == time) // (i == 1500)` for 25 minutes
        {
            // Play audio notification (relative to `src`)
            playAudio("ending.mp3");
        }

    }
}




