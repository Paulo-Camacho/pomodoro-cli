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
    auto startTime = std::chrono::system_clock::now();
    auto rsTime = std::chrono::system_clock::to_time_t(startTime);

    std::cout << "\nStart time: " << std::ctime(&rsTime) << std::endl;

    std::ofstream logging;
    logging.open("log.md", std::ios::app);
    if (logging.is_open()) 
    {
        logging << "This is the start time " << std::ctime(&rsTime) << std::endl;
        logging.close();
    } 
    else 
    {
        std::cerr << "Something went wrong with opening the file" << std::endl;
    }

    while (!stop) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++counter;
        ++log;
        std::cout << "\rIt has been " << counter << " seconds and " << counter / 60 << " minutes " << std::flush;
        if (counter == time) // i == 1500 for 25 minutes
        {
            std::cout << "The inner loop ran. This is the number of total seconds set " << counter << std::endl;
            stop = true;
        }

    }
    std::cout << "Congrats it's been: " << log / 60 << " minutes and " << log << " seconds " << std::endl;
    
    system("paplay ~/Projects/Pomodoro/assets/ending.mp3 &");

    auto endTime = std::chrono::system_clock::now();
    auto reTime = std::chrono::system_clock::to_time_t(endTime);

    auto difference = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
    int totalSeconds = difference.count();

    int minutes = totalSeconds / 60; 
    int seconds = totalSeconds % 60;

    std::cout << "Duration: " << minutes << " minutes and " << seconds << " seconds." << std::endl;

    std::cout << std::ctime(&reTime) << std::endl;

    logging.open("log.md", std::ios::app);
    if (logging.is_open()) 
    {
        logging << "This is the end time " << std::ctime(&reTime) << std::endl;
        logging.close();
    } 
    else 
    {
        std::cerr << "Something went wrong with opening the file" << std::endl;
    }
}
