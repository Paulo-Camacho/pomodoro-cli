#include "Request.hpp"
#include "Timer.hpp"
#include <iostream>

Request::Request(Session i) : init(i) {}


void Request::ask()
{
    std::cout << "What are we studying today and how long? " << std::endl;
    std::getline(std::cin, q);

}
