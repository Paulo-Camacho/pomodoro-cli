#include "Button.h"

Button::Button(float x, float y, float width, float height, const std::string& text) {
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(500, 500));
    shape.setFillColor(sf::Color::Blue);  // Example color

    if (!font.loadFromFile("./assets/0xProtoNerdFont-Regular.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
    }

    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(24);  // Example size
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(x + 10, y + 10);  // Simple positioning
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(buttonText);
}

