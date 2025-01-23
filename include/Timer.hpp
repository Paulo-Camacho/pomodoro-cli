#ifndef TIMER_HPP
#define TIMER_HPP
#include <fstream>
class Timer {
public:
    Timer(double t);
    void printTimer();
    auto startTime();
    auto endTime();

    double logTime();
private:
    double time;
    double log;
    double counter;
    bool   stop;
    std::ofstream logging;
    
};

#endif // TIMER_HPP
