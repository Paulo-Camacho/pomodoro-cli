#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

class Timer
{
public:
    double totalSeconds;
    Timer(double minutes);
    void start();
};

#endif // TIMER_H
