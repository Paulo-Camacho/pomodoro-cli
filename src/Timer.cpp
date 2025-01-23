#include <Timer.hpp>
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

Timer::Timer(double t) : time(t * 60), log(0), counter(0), stop(false) {}


void Timer::printTimer()
{
    
    auto startTime = std::chrono::system_clock::now();
    auto sTime = std::chrono::system_clock::to_time_t(startTime);

    std::cout << std::ctime(&sTime)<< std::endl;

    std::ofstream logging;
    logging.open("log.md", std::ios::app);
    if (logging.is_open()) 
    {
        logging << "This is the start time " << std::ctime(&sTime) << std::endl;
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


    auto endTime = std::chrono::system_clock::now();
    auto eTime = std::chrono::system_clock::to_time_t(endTime);

    std::cout << std::ctime(&eTime)<< std::endl;

    logging.open("log.md", std::ios::app);
    if (logging.is_open()) 
    {
        logging << "This is the end time " << std::ctime(&sTime) << std::endl;
        logging.close();
    } 
    else 
    {
        std::cerr << "Something went wrong with opening the file" << std::endl;
    }



}

double Timer::logTime() {
    return log;
}
