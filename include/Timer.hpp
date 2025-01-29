#ifndef TIMER_HPP
#define TIMER_HPP
#include <fstream>
#include "Subject.hpp"

class Timer 
{
public:
    Timer(double t);
    void printTimer();
    auto startTime();
    auto endTime();
    void getSubject(const Subject& subject);
private:
    double time;
    double log;
    double counter;
    bool   stop;
    std::ofstream logging;
    const Subject* subjectPtr;
};

#endif // TIMER_HPP
