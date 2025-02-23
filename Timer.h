#ifndef TIMER_H_
#define TIMER_H_
#include <string>

struct Timer
{
    Timer();
    Timer(double n);

    void pomodoro(const std::string& subject);
    double seconds;
};

#endif // TIMER_H_
