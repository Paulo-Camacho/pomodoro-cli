#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <thread>

class Timer
{
public:
    Timer(double minutes);
    void start();
private:
    double totalSeconds;
};

#endif // TIMER_H
