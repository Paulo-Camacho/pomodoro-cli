// while(true) {
//     std::cout << "\nTOTAL STUDY TIME :: MINUTES : " << hold.seconds / 60 << "
//     SECONDS : " << hold.seconds << std::endl; std::cout << "" << std::endl;
//     std::cout << "|d : DEBUG                      |"    << std::endl;
//     std::cout << "|l : Log a Subject              |"    << std::endl;
//     std::cout << "|s : Start Timer For 25 Minutes |"    << std::endl;
//     std::cout << "|b : Start Timer For 5  Minutes |"    << std::endl;
//     std::cout << "|c : Start Timer For x  Minutes |"    << std::endl;
//     std::cout << "|q : Quit                       |"    << std::endl;
//     std::cout << "" << std::endl;

//     std::cin >> start;
//     if(start == 'l' || start == 'L')
//     {
//         std::cout << "\nPlease enter the desired Subject to log" <<
//         std::endl; std::cin >> subject; std::cout << "\nNOW LOGGING : " <<
//         subject << std::endl;
//     }
//     // ------------------DEBUG----------------------
//     else if(start == 'd' || start == 'D')
//     {
//         Timer kick(0.1);
//         kick.pomodoro(subject);
//         hold.seconds += (0.1) * 60;
//     }
//     else if(start == 's' || start == 'S')
//     {
//         Timer kick(25);
//         kick.pomodoro(subject);
//         hold.seconds += 25 * 60;
//     }
//     else if(start == 'b' || start == 'B')
//     {
//         Timer kick(5);
//         kick.pomodoro(subject);
//         hold.seconds += 5 * 60;
//     }
//     else if(start == 'x' || start == 'X')
//     {
//         std::cout << "Please enter the desired amount of time" << std::endl;
//         std::cin >> custom;
//         Timer kick(custom);
//         kick.pomodoro(subject);
//         hold.seconds += 5 * 60;
//     }
//     else if(start == 'q' || start == 'Q')
//     {
//         std::cout << "\nHave a great day! " << std::endl;
//         break;
//     }
// }

#include "Ask.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

Ask::Ask() : start('\0'), debug('\0'), custom(0), subject("") {}

void Ask::prompt(Timer &hold) {
  float windowX = 500.f;
  float windowY = 500.f;
  sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Pomodoro");

  sf::Font proto;
  if (!proto.loadFromFile("./assets/0xProtoNerdFont-Regular.ttf")) {
    std::cerr << "The font was not loaded" << std::endl;
  }

  sf::Text play("play", proto, 150);
  play.setPosition(windowX/2, windowY-windowY);
  sf::Text quit("quit", proto, 150);
  quit.setPosition(windowX/2, play.getCharacterSize());
  window.setFramerateLimit(60);


  // Testing
  sf::Text text("", proto, 100);
  text.setFillColor(sf::Color::Yellow);
  text.setPosition(windowX/2, windowY-windowY); // Center the text on the window

  float countdownDuration = 10.0f;
  float timeRemaining = countdownDuration;

  sf::Clock clock;


  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }


    sf::Time elapsed = clock.getElapsedTime();
        timeRemaining = countdownDuration - elapsed.asSeconds();

if (timeRemaining < 0) {
            text.setString("Time's up!");
        } else {
            text.setString("Time: " + std::to_string(static_cast<int>(timeRemaining)));
        }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      std::cout << "Hello, world " << std::endl;

         Timer kick(0.1);
         kick.pomodoro(subject);
         hold.seconds += (0.1) * 60;

    }

    window.clear();
    window.draw(text);
    window.display();
  }
}
