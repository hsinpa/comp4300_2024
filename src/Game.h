//
// Created by hsinp on 2024/10/04.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "entt.hpp"

class Game {
    std::unique_ptr<sf::RenderWindow> _window;
    std::unique_ptr<entt::registry> _registry;
    static inline float DELTA_TIME = 0;

    // Creation
    void create_player();

    // System
    void sprocess_input(sf::Keyboard::Scancode& scancode, int is_press);
    void sprocess_render();

public:
    Game(const unsigned int width, const unsigned int height, const unsigned int fps) {
        _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "CMake SFML Project");
        _registry = std::make_unique<entt::registry>();

        _window->setFramerateLimit(fps);
    }

    void init();

};



#endif //GAME_H
