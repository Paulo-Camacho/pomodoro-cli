#include <SFML/Graphics.hpp>
#include <iostream>
#include <Timer.hpp>

int main()
{
    std::cout << "Hello, world " << std::endl;
    Timer example(1);
    example.printTimer();
}
