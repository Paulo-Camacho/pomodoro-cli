#include <SFML/Graphics.hpp>
#include <Timer.hpp>
#include <Prompt.hpp>
#include <iostream>
#include <string>

int main() {

    Prompt prompt('s', 'b', 'c', 'q');
    std::string pregunta = "null";
    std::string subject;
    std::cout << "Would you like to enter a subject? [Y/n]"; // Any other output that this quits the program
    //std::cin >> pregunta;
    std::getline(std::cin, pregunta);
    if(pregunta == "yes" || pregunta == "y" || pregunta == "Y")
    {
        std::cout << "Great, enter it now. " << std::endl;
        std::getline(std::cin, subject);
        //std::cin >> subject;
    } 
    else if (pregunta == "no" || pregunta == "n")
    {
        std::cout << "No subject will be logged " << std::endl;
    }
    else if (pregunta != "valid entry")
    {
        std::cout << "To log please enter the 'y' or 'n' next time " << std::endl;
    }
    else
    {
        std::cout << "Input was not recorded " << std::endl;
    }
    prompt.printMenu(subject);
    return 0;
}
