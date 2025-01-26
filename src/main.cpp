#include <SFML/Graphics.hpp>
#include <Timer.hpp>
#include <Prompt.hpp>

int main() {

    Prompt menu('s', 'b', 'c', 'q');

    menu.printMenu();

    return 0;
}
