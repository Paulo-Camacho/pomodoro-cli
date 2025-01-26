#include "Prompt.hpp"
#include "Timer.hpp"
#include <iostream>

// When these variables are printed, the words inherit the chars that I defined
Prompt::Prompt(char s, char b, char c, char q) : start(s), breather(b), custom(c), quit (q) {}

void Prompt::printMenu() {
    std::cout << "Menu Options:\n";
    std::cout << start << ": Start 25-minute Timer" << std::endl;
    std::cout << breather << ": Start 5-minute Timer" << std::endl;
    std::cout << custom << ": Custom Timer" << std::endl;
    std::cout << quit << ": Quit" << std::endl;
    std::cout << "d: Debug" << std::endl;

    char choice;
    std::cin >> choice;

    if (choice == start) {
        Timer timer(25); 
        timer.printTimer();
        printMenu();
    } else if (choice == breather) {
        std::cout << "Enjoy your break!" << std::endl;
        Timer timer(5);
        timer.printTimer();
        printMenu();
    } else if (choice == custom) {
        double customTime;
        std::cout << "Custom Timer" << std::endl;
        std::cin >> customTime;
        Timer timer(customTime);
        timer.printTimer();
        printMenu();
    } else if (choice == quit) {
        std::cout << "Exiting..." << std::endl;
    } else if (choice == 'd') {
        Timer timer(0.1);
        timer.printTimer();
        printMenu();
    }  
    else {
        std::cout << "Invalid choice. Try again." << std::endl;
        printMenu();
    }
}
