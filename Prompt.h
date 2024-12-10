#ifndef PROMPT_H
#define PROMPT_H
#include <string>
#include <iostream>

class Prompt
{
public:

    //Prompt(const std::string q) : category(q) {}
    Prompt(std::string q);
    void question();

private:
    std::string category;
};

#endif
