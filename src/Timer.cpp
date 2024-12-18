#include "Timer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

// I will not include pausing feature. FULL SEND! 
Timer::Timer(double t) : totalSeconds(t * 60.0) {}

void Timer::logic()
{
    std::cout << "STARTING TIMER OF " << totalSeconds / 60.0 << " MINUTES" << std::endl;
    system("paplay ~/projects/pomodoro/assests/letsDoThis.mp3");

    for(int i = 0; i <= totalSeconds; i++) //  This will only iterate if i is >= to 0.
    {
        seconds = i;
        minutes = i / 60.0;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rMINUTES: " << minutes << " SECONDS: " << seconds << std::flush;
    }
    std::cout << "\nAll done!" << std::endl; 
    system("paplay ~/projects/pomodoro/assests/done.wav");
}
