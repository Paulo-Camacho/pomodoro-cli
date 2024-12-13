#ifndef TIMER_HPP 
#define TIMER_HPP 

class Timer
{
public:
    Timer(double t);
    void logic();
private:
    int totalSeconds; 
    int minutes;
    int seconds;
};

#endif // TIMER_HPP
