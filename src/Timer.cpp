#include <Timer.hpp>
#include <iostream>
#include <chrono>
#include <thread>

Timer::Timer(double t) : time(t * 60) {}

void Timer::printTimer()
{
    for(int i = 0; i <= time; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "This is the " << i << " iteration " << std::endl;
    }
}
