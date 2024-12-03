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
    char question{};
    Prompt(char hold) : question(hold) {}

    void start()  
    {
        std::cout << "Would you like to start? " << std::endl;
        if(question == 'y')
        {
            std::cout << "Hello world! ";
        }
    }
};


int main()
{
    Prompt pomodoro('y');
    pomodoro.start();
    return 0;
}
