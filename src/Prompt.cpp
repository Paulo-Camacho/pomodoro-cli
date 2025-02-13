#include "Prompt.hpp"
#include "Timer.hpp"
#include <iostream>

// When these variables are printed, the words inherit the chars that I defined
Prompt::Prompt(char s, char b, char c, char q) : start(s), breather(b), custom(c), quit (q), check('\0') {}

void Prompt::printMenu(const std::string& subject) 
    {
    const std::string &hold = subject;
    char choice;
    std::cout << "Now logging " << hold << std::endl;
    std::cout << "Menu Options:\n";
    std::cout << start << ": Start 25-minute Timer" << std::endl;
    std::cout << breather << ": Start 5-minute Timer" << std::endl;
    std::cout << custom << ": Custom Timer" << std::endl;
    std::cout << quit << ": Quit" << std::endl;
    std::cout << "d: Debug" << std::endl;

    std::cin >> choice;

    if (choice == start) {
        Timer timer(25, subject); 
        timer.printTimer();
        printMenu(subject);
    } else if (choice == breather) {
        std::cout << "Enjoy your break!" << std::endl;
        Timer timer(5, subject);
        timer.printTimer();
        printMenu(subject);
    } else if (choice == custom) {
        double customTime;
        std::cout << "Custom Timer" << std::endl;
        std::cin >> customTime;
        Timer timer(customTime, subject);
        timer.printTimer();
        printMenu(subject);
    } else if (choice == quit) {
        std::cout << "Exiting..." << std::endl;
    } else if (choice == 'd') {
        Timer timer(0.1, subject);
        std::cout << "\nNow logging " << hold;
        timer.printTimer();
        printMenu(subject);
    }  
    else {
        std::cout << "Invalid choice. Try again." << std::endl;
        printMenu(subject);
    }
}
