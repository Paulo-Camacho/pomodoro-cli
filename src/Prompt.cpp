#include "Prompt.hpp"
#include "Timer.hpp"
#include <iostream>

Prompt::Prompt(char s, char c, char q) : start(s), custom(c), quit (q) {}

void Prompt::printMenu() {
    std::cout << "Menu Options:\n";
    std::cout << start << ": Start 25-minute Timer\n";
    std::cout << custom << ": Set Custom Timer\n";
    std::cout << quit << ": Quit\n";

    char choice;
    std::cin >> choice;

    if (choice == start) {
        Timer timer(25); // 25 minutes
        timer.printTimer();
        printMenu(); // Recursive call to display menu again
    } else if (choice == custom) {
        int customTime;
        std::cout << "Enter custom time in minutes: ";
        std::cin >> customTime;
        Timer timer(customTime);
        timer.printTimer();
        printMenu(); // Recursive call to display menu again
    } else if (choice == quit) {
        std::cout << "Exiting...\n";
    } else {
        std::cout << "Invalid choice. Try again.\n";
        printMenu(); // Recursive call to display menu again
    }
}
