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
    for(int i = 0; i < seconds; ++i)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\rI have slept for : " << i + 1 << " seconds " << std::flush;
    }
    auto endTime = std::chrono::system_clock::now();
    // auto totalEndTime += endTime;
    auto humanETime = std::chrono::system_clock::to_time_t(endTime);
    std::cout << "\nTimer is finished, have a great day! " << std::endl;

    std::ofstream log;
    log.open("./record.md", std::ios::app);
    if(log.is_open())
    {

        log << "Subject: " << (subject.empty() ? "Null " : subject) << "\n";
        log << "Started study time " << std::ctime(&humanSTime);
        log << "Ended total " << std::ctime(&humanETime) << std::endl;
    }

}
