#include "Timer.h"

int main()
{
    std::cout << 114 % 60 << std::endl; // This does instead produced the 54 from the timer.
    Timer example(2);
    example.start();  
    return 0;
}
