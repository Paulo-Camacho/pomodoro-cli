#include <iostream>

struct menu 
{
    void dialogue()
    {
        std::cout << "Would you like to start? " << std::endl;
    }
};

struct Clock
{

    menu show;
    int store;
    
    void clock()
    {
    show.dialogue();
    std::cin >> store;
        if(store == 1) 
        {
            std::cout << "Hey, this works " << std::endl;
        } else if (store == 0)
            {
            std::cout << "Goodbye! " << std::endl;
            } else 
                {
                    std::cout << "Try again with either 1 or 0 " << std::endl;
                }
    }
};

int main() {

    Clock timer; 
    timer.clock();
    return 0;

}
