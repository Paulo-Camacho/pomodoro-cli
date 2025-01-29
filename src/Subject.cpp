#include "Subject.hpp"
#include "Prompt.hpp"
#include <iostream>
#include <limits>
#include <string>

Subject::Subject() {
    // Constructor implementation
}

void Subject::displayQuestion() {
    char input;
    std::string subject;
    std::cout << "Subject to track? Enter 'Y' or 'N' " << std::endl;
    
    std::cin >> input;
    // See the double check here
    if(input == 'y' || input == 'Y') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears input buffer
        std::cout << "Please enter the subject " << std::endl;
        std::getline(std::cin, subject);
        std::cout << "Subject: " << subject << std::endl;
        Prompt menu('s', 'b', 'c', 'q');
        menu.printMenu();
    } 
    // Implementation here
}

std::string Subject::getSubject() const {
    return subject;
}
