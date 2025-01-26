#include <Timer.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib>

Timer::Timer(double t) : time(t * 60), log(0), counter(0), stop(false) {}

void Timer::printTimer()
{
    // Logging the start and displaying it
    auto startTime = std::chrono::system_clock::now();
    auto rsTime = std::chrono::system_clock::to_time_t(startTime);
    std::cout << "\nStart time: " << std::ctime(&rsTime) << std::endl;

    // Timer loop
    while (!stop) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++counter;
        std::cout << "\rIt has been " << counter << " seconds and " << counter / 60 << " minutes " << std::flush;
        if (counter == time) // i == 1500 for 25 minutes
        {
            std::cout << "The inner loop ran. This is the number of total seconds set " << counter << std::endl;
            stop = true;
        }

    }

    // End of timer
    system("paplay ~/Projects/Pomodoro/assets/ending.mp3 &"); // Playing during program

    auto endTime = std::chrono::system_clock::now();
    auto reTime = std::chrono::system_clock::to_time_t(endTime);

    auto difference = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    int totalSeconds = difference.count();

    int minutes = totalSeconds / 60; 
    int seconds = totalSeconds % 60;

    std::cout << "Duration: " << minutes << " minutes and " << seconds << " seconds." << std::endl;

    std::cout << "Ending time : " << std::ctime(&reTime) << std::endl;

    std::ofstream logging;
    logging.open("/home/waifu/Projects/Pomodoro/newnew.md", std::ios::app);
    if (logging.is_open()) 
    {
        // logging << "This is the start time " << std::ctime(&rsTime) << std::endl;
        logging << "\nStart time was: " << std::ctime(&rsTime) << "Ending time was " << std::ctime(&reTime) << "Totaling the total study time to: " << minutes << " minutes and seconds " << seconds << std::endl;
        logging.flush();
        logging.close();
    } 
    else 
    {
        std::cerr << "Something went wrong with opening the file" << std::endl;
    }
}
