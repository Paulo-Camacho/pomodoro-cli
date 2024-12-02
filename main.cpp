#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>  // Include for using the system()

class Timer
{
public:
    int totalSeconds;
    Timer(int minutes) : totalSeconds(minutes * 60) {}  // Interesting constructor syntax

    void start()
    {
        for (int i = totalSeconds; i > 0; i--)
        {
            int secondsCounter = i;
            int minuteCounter = secondsCounter / 60;
            std::cout << "\rMinutes:  " << minuteCounter << " Seconds: " << secondsCounter % 60 << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "\nTime is up! Good job!\n" << std::endl;
        
        system("paplay ~/data/piano.mp3");  // Replace /path/to/your/Alarm.wav
    }
};

int main()
{
    std::cout << "Pomodoro Timer started " << std::endl;
    Timer pomodoro(25);
    pomodoro.start();

    return 0;
}
