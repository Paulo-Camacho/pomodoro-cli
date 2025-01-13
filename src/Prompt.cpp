#include "Prompt.hpp"
#include "Timer.hpp"
#include <iostream>

// When these variables are printed, the words inherit the chars that I defined
Prompt::Prompt(char s, char c, char q) : start(s), custom(c), quit (q) {}

void Prompt::printMenu() 
{
    std::cout << "Menu Options:\n";
    std::cout << start << ": Start 25-minute Timer\n";
    std::cout << custom << ": Set Custom Timer\n";
    std::cout << quit << ": Quit\n";

    char choice;
    std::cin >> choice;

    if (choice == start) {
        Timer timer(25); 
        timer.printTimer();
        printMenu();
    } else if (choice == custom) {
        double customTime;
        std::cout << "Enter custom time in minutes: ";
        std::cin >> customTime;
        Timer timer(customTime);
        timer.printTimer();
        printMenu();
    } else if (choice == quit) {
        std::cout << "Exiting...\n";

    } else if (choice == 'd') {
        Timer timer(0.1);
        timer.printTimer();
        printMenu();
    }  


    else {
        std::cout << "Invalid choice. Try again.\n";
        printMenu();
    }
}
