#include <Timer.hpp>
#include <iostream>
#include <chrono>
#include <thread>

Timer::Timer(double t) : time(t * 60) {}

void Timer::printTimer()
{
    bool run = false;
    double counter{}; 
    double     log{};
    
    while (!run) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++counter;
        ++log;
        std::cout << "\rIt has been " << counter << " seconds and " << counter / 60 << " minutes" << std::flush;
        if (counter == time) // i == 1500 for 25 minutes
        {
            std::cout << "Inner loop ran, this is the number of total seconds set " << counter << std::endl;
            run = true;
        }

    }
    std::cout << "Congrats it's been: " << log / 60 << " minutes and " << log << " seconds " << std::endl;
}
