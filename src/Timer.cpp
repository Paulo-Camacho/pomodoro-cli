#include <Timer.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

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
        std::cout << "\rIt has been " << counter << " seconds and " << counter / 60 << " minutes " << std::flush;
        if (counter == time) // i == 1500 for 25 minutes
        {
            std::cout << "The inner loop ran. This is the number of total seconds set " << counter << std::endl;
            run = true;
        }

    }

    system("play -n synth 8 sine 300 gain -15");
    std::cout << "Congrats it's been: " << log / 60 << " minutes and " << log << " seconds " << std::endl;
}
