#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // Include for using the system()

class Timer
{
public:
    double totalSeconds;
    Timer(double minutes) : totalSeconds(minutes * 60) {}  // Interesting constructor syntax

    void start()
    {
        for (double i = totalSeconds; i > 0; i--)
        {
            int secondsCounter = i;
            int minuteCounter = secondsCounter / 60;
            std::cout << "\rMinutes:  " << minuteCounter << " Seconds: " << secondsCounter % 60 << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "\nEnd of timer " << std::endl; 
        system("paplay ~/data/piano.mp3");  // Replace /path/to/your/Alarm.wav
        }
};

class Prompt
{
public:
    int question = 0;

    void proceede()
    {
        
        std::cout << "The Pomodoro Timer has started, good luck and have fun!" << std::endl;
        Timer pomodoro(25);
        Timer ender(5);
        pomodoro.start();        
        std::cout << "5 minute break? Enter 1/YES 0/NO " << std::endl;
        std::cin >> question;
            if(question == 1)
            {
               ender.start();
            }
        std::cout << "Have a good day! " << std::endl;
    }
};

int main()
{
    Prompt reloj;
    reloj.proceede();
    return 0;
}
