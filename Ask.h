#ifndef ASK_H
#define ASK_H
#include <string>
#include "Timer.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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
