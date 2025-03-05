#include "Ask.h"
#include "Timer.h"
#include <iostream>

Ask::Ask() : start('\0'), debug('\0'), custom(0), subject("") {}

void Ask::prompt(Timer& hold)
{
    while(true) {
        std::cout << "\nTOTAL STUDY TIME :: MINUTES : " << hold.seconds / 60 << " SECONDS : " << hold.seconds << std::endl;
        std::cout << "" << std::endl;
        std::cout << "|d : DEBUG                      |"    << std::endl;
        std::cout << "|l : Log a Subject              |"    << std::endl;
        std::cout << "|s : Start Timer For 25 Minutes |"    << std::endl;
        std::cout << "|b : Start Timer For 5  Minutes |"    << std::endl;
        std::cout << "|c : Start Timer For x  Minutes |"    << std::endl;
        std::cout << "|q : Quit                       |"    << std::endl;
        std::cout << "" << std::endl;

        std::cin >> start;
        if(start == 'l' || start == 'L')
        {
            std::cout << "\nPlease enter the desired Subject to log" << std::endl;
            std::cin >> subject;
            std::cout << "\nNOW LOGGING : " << subject << std::endl;
        }
        // ------------------DEBUG----------------------
        else if(start == 'd' || start == 'D')
        {
            Timer kick(0.1);
            kick.pomodoro(subject);
            hold.seconds += (0.1) * 60;
        }
        else if(start == 's' || start == 'S')
        {
            Timer kick(25);
            kick.pomodoro(subject);
            hold.seconds += 25 * 60;
        }
        else if(start == 'b' || start == 'B')
        {
            Timer kick(5);
            kick.pomodoro(subject);
            hold.seconds += 5 * 60;
        }
        else if(start == 'x' || start == 'X')
        {
            std::cout << "Please enter the desired amount of time" << std::endl;
            std::cin >> custom;
            Timer kick(custom);
            kick.pomodoro(subject);
            hold.seconds += 5 * 60;
        }
        else if(start == 'q' || start == 'Q')
        {
            std::cout << "\nHave a great day! " << std::endl;
            break;
        }
    }
}
