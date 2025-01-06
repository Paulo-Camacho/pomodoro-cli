#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
    public:
    Timer(double t);
    void printTimer();
    private:
    double time;
    int totalTime;
    int minutes;
    int seconds;
    bool run;
};

#endif // TIMER_HPP
