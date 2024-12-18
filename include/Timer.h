#ifndef TIMER_H 
#define TIMER_H 

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

#endif // TIMER_H
