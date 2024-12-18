#include "Timer.h"
#include "Session.h"
#include <iostream>
#include <string>
#include <limits>  // Required for std::numeric_limits

int main(int argc, char* argv[]) {
    std::string subject;
    double duration;

    // Prompt user to input subject and duration in the same line
    std::cout << "Enter the subject and duration (e.g., Physics 25): ";
    while (!(std::cin >> subject >> duration) || duration <= 0) {
        std::cout << "Invalid input. Format: <subject> <duration>. Duration must be positive.\n";
        std::cin.clear();  // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
        std::cout << "Try again: ";
    }

    // Create Session object with the provided input
    Session session(subject, duration);

    // Create a Timer object and run the logic
    Timer start(session.getDuration());
    start.logic();

    return 0;
}
