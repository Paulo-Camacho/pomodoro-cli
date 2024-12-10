#include "Timer.h"

    Timer::Timer(double m) : totalSeconds(m * 60) {}  // Interesting constructor syntax

    void Timer::start()
    {
        for (double i = totalSeconds; i > 0; i--)
        {
            int secondsCounter = i;
            int minuteCounter  = secondsCounter / 60;
            std::cout << "\rMinutes: " << minuteCounter << " Seconds: " << secondsCounter % 60 << " Raw i value: " << i << std::flush;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "\033[2K\r"; // This clears the line 
        std::cout << "End of timer " << std::endl; 
        system("paplay ~/piano.mp3");  
    }
