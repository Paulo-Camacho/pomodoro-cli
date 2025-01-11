#include <Timer.hpp>
#include <iostream>
#include <chrono>
#include <thread>

Timer::Timer(double t) : time(t * 60) {}

// Timer function
void Timer::printTimer()
{
    bool run = true;
    int counter = 0;
    double log{};



    while (run) 
    {

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "DEBUG: time in seconds" << time << std::endl;

        std::cout << "\rIt has been " << counter << " seconds. " << std::flush;
        if (counter == time) // i == 1500 for 25 minutes
        {
            run = false;
        }

        counter++;
        log++;
    }
    
    std::cout << "Congrats - Minutes:  " << log * 60 << " and Seconds : " << log << std::endl;
}
