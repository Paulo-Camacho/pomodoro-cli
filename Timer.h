#ifndef TIMER_H
#define TIMER_H
#include <string>

struct Timer
{
    Timer();
    Timer(double n);

    void pomodoro(const std::string& subject);
    double seconds;
};

#endif // TIMER_H
