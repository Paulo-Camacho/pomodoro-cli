#ifndef ASK_H
#define ASK_H
#include <string>
#include "Timer.h"

struct Ask
{
    Ask(); // Default constructor declaration
    void prompt(Timer& hold);
    char start;
    char debug;
    double custom;
    std::string subject;

};

#endif // ASK_H
