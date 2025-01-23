#include "Prompt.hpp"
#include "Timer.hpp"
#include <iostream>

// When these variables are printed, the words inherit the chars that I defined
Prompt::Prompt(char s, char c, char q) : start(s), custom(c), quit (q) {}

void Prompt::printMenu() {
    std::cout << "Menu Options:\n";
    std::cout << start << ": Start 25-minute Timer" << std::endl;
    std::cout << custom << ": Set Custom Timer" << std::endl;
    std::cout << quit << ": Quit" << std::endl;
    std::cout << "d: Debug" << std::endl;

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
        double result = timer.logTime(); 
        std::cout << "This is the logged time " << result << std::endl;
    }  

    else {
        std::cout << "Invalid choice. Try again.\n";
        printMenu();
    }



}
