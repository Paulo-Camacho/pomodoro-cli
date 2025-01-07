#include <SFML/Graphics.hpp>
#include <iostream>
#include <Timer.hpp>
#include <Prompt.hpp>



int main() {
    // Create an instance of Prompt
    Prompt menu('s', 'c', 'q'); // Example arguments for start, custom, and quit

    // Call the printMenu method
    menu.printMenu();

    return 0;
}
