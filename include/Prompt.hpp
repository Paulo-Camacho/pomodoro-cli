#ifndef PROMPT_HPP
#define PROMPT_HPP
class Prompt
{
    public:
        Prompt(char s, char b, char c, char q);
        void printMenu();
    private:
        char     start;
        char  breather;
        char    custom;
        char      quit;
        char     input;


        double customTime;


};

#endif // PROMPT_HPP
