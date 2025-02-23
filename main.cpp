#include <iostream>
#include <string>
#include "Timer.h"
#include "Ask.h"

int main()
{
    Timer timer(0);
    Ask ask;
    ask.prompt(timer);
    return 0;
}
