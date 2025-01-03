#include <Timer.hpp>
#include <SFML/Audio.hpp> // Include SFML Audio for playing sound
#include <iostream>
#include <chrono>
#include <thread>

Timer::Timer(double t) : time(t * 60) {}

void Timer::printTimer()
{
    sf::Music opening;

    if (!opening.openFromFile("./letsDoThis.mp3")) // Load the MP3 file
    {
        std::cerr << "Failed to load the MP3 file. Check the path!" << std::endl;
        return;
    }

    opening.play();
    std::cout << "Playing audio: letsDoThis.mp3" << std::endl;

    while (opening.getStatus() == sf::Music::Playing)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Actual timer incrementing
    for (int i = 0; i <= time; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int minutes = (time - i) / 60;
        int seconds = time - i;
        std::cout << "\rMINUTES REMAINING: " << minutes << " SECONDS REMAINING: " << seconds << std::flush;

    }
    
    sf::Music closing;

    if (!closing.openFromFile("./ending.mp3")) // Load the MP3 file
    {
        std::cerr << "Failed to load the MP3 file. Check the path!" << std::endl;
        return;
    }

    closing.play();
    std::cout << "\nPlaying audio: ending.mp3" << std::endl;

    while (closing.getStatus() == sf::Music::Playing)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }    

}
