#ifndef TIMER_HPP
#define TIMER_HPP

class Timer
{
    public:
        Timer(double t);
        void printTimer();
    private:
        double time;
        int minutes;
        int seconds;
        bool run;
        double counter;
        double log;
};

#endif // TIMER_HPP
