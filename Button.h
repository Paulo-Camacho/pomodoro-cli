#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float x, float y, float width, float height, const std::string& text);

    void draw(sf::RenderWindow& window);
    bool isClicked(sf::Event event);

private:
    sf::RectangleShape shape;
    sf::Text buttonText;
    sf::Font font;
};

#endif
