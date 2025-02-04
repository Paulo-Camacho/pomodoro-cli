#ifndef TIMER_HPP
#define TIMER_HPP
#include <string>
#include <fstream>

class Timer 
{
public:
    Timer(double t, const std::string& subject);
    void printTimer();
    auto startTime();
    auto endTime();
private:
    double time;
    double log;
    double counter;
    bool   stop;
    std::string logged;
    std::ofstream logging;
};

#endif // TIMER_HPP
