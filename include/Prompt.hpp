#ifndef PROMPT_HPP
#define PROMPT_HPP
#include <string>
class Prompt
{
    public:
        Prompt(char s, char b, char c, char q);
        void printMenu(const std::string& subject);
    private:
        char     start;
        char  breather;
        char    custom;
        char      quit;
        char     input;

        char     check;


        double customTime;


};

#endif // PROMPT_HPP
