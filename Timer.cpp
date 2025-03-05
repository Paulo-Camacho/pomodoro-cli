#include "Timer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

Timer::Timer(double n) : seconds(n * 60) {}

void Timer::pomodoro(const std::string& subject)
{
    auto startTime = std::chrono::system_clock::now();
    auto humanSTime = std::chrono::system_clock::to_time_t(startTime);
    std::cout << "\nStart time: " << std::ctime(&humanSTime) << std::endl;
    std::cout << "Timer started for : " << seconds / 60 << " minutes" << std::endl;

    // Timer logic
    for(int i = 0; i < seconds; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rI have slept for  : " << i + 1 << " SECONDS" << " and : " << (i + 1) / 60 << " MINUTES " << std::flush;
    }
    auto endTime = std::chrono::system_clock::now();
    // auto totalEndTime += endTime;
    auto humanETime = std::chrono::system_clock::to_time_t(endTime);
    std::cout << "" << std::endl;
    std::cout << "\nTimer is finished " << std::endl;

    std::ofstream log;
    log.open("./record.md", std::ios::app);
    if(log.is_open())
    {
        log << (subject.empty() ? "" : subject) << "\n";
        log << "STARTED : " << std::ctime(&humanSTime);
        log << "ENDED   : " << std::ctime(&humanETime);
    }
}
