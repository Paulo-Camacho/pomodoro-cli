#include "Timer.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
// NO PAUSING FEATURE ARRRGHHHHH!!!
// This flavor of my timer increaments from the given value.
Timer::Timer(double t) : totalSeconds(t * 60) {}

void Timer::logic()
{
    system("paplay ~/projects/pomodoro/assests/letsDoThis.mp3");
    for(int i = 0; i <= totalSeconds; ++i) //  This will only iterate if i is >= to 0.
    {
        seconds = i;
        minutes = i / 60;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rSECONDS: " << seconds << " MINUTES : " << minutes << std::flush;
    }
    std::cout << "\nAll done!" << std::endl; 
    system("paplay ~/projects/pomodoro/assests/done.wav");
}
