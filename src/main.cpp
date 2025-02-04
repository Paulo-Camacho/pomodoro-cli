#include <SFML/Graphics.hpp>
#include <Timer.hpp>
#include <Prompt.hpp>
#include <iostream>
#include <string>

int main() {

    Prompt prompt('s', 'b', 'c', 'q');
    std::string pregunta = "null";
    std::string subject;
    std::cout << "Would you like to enter a subject? ";
    std::cin >> pregunta;
    if(pregunta == "yes" || pregunta == "y")
    {
        std::cout << "Great, enter it now. " << std::endl;
        std::cin >> subject;
    } 
    else if (pregunta == "no" || pregunta == "n")
    {
        std::cout << "No subject will be logged " << std::endl;
    }
    else 
    {
        std::cout << "Something went wrong " << std::endl;
    }
    std::cout << subject << " is now being logged"<< std::endl;
    prompt.printMenu(subject);
    return 0;
}
