//
// Created by hsinp on 2024/10/04.
//

#include "Game.h"

#include <iostream>

#include "Entities.h"
#include "Components.hpp"

// Init Process
void Game::init() {
    sf::Clock deltaClock;
    create_player();

    while (_window->isOpen())
    {
        sf::Time dt = deltaClock.restart();
        Game::DELTA_TIME = dt.asSeconds();
        for (auto event = sf::Event{}; _window->pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                _window->close();
            }

            if (event.type == sf::Event::KeyPressed) {
                sprocess_input(event.key.scancode, 1);
            }

            if (event.type == sf::Event::KeyReleased) {
                sprocess_input(event.key.scancode, -1);
            }
        }
        _window->clear();

        sprocess_render();

        _window->display();
    }
}

void Game::create_player() {
    const auto entity = _registry->create();
    _registry->emplace<PlayerComponent>(entity);
    _registry->emplace<CMovableComponent>(entity, 100);
    _registry->emplace<CTransform>(entity, Vec2f(200, 400), Vec2f(0, 0), 0, 50);
    _registry->emplace<CShape>(entity, 30, 12, sf::Color::Blue, sf::Color::Green, 2);
}

// System Process
void Game::sprocess_render() {
    auto multi = _registry->view<CTransform, CShape, CMovableComponent>();
    for(auto entity: multi) {
        // a component at a time ...
        auto &transfrom = multi.get<CTransform>(entity);
        auto &shape = multi.get<CShape>(entity);
        auto &movable = multi.get<CMovableComponent>(entity);

        transfrom.pos = transfrom.pos + (transfrom.velocity * movable.speed * DELTA_TIME);
        transfrom.angle = transfrom.angle + (transfrom.angular_velocity * DELTA_TIME);

        shape.circle.setPosition(transfrom.pos.x(), transfrom.pos.y());
        shape.circle.setRotation(transfrom.angle);

        _window->draw(shape.circle);
    }
}

void Game::sprocess_input(sf::Keyboard::Scancode& scancode, int is_press) {
    auto player_view = _registry->view<PlayerComponent, CTransform>();

    for(auto entity: player_view) {
        auto &transform = player_view.get<CTransform>(entity);

        // Up
        if (scancode == sf::Keyboard::Scan::W) {
            transform.velocity.set(transform.velocity.x(), std::clamp(transform.velocity.y() - (1 * is_press), -1.f, 1.f) );
        }

        // Down
        if (scancode == sf::Keyboard::Scan::S) {
            transform.velocity.set(transform.velocity.x(), std::clamp(transform.velocity.y() + (1 * is_press), -1.f, 1.f));
        }

        // Right
        if (scancode == sf::Keyboard::Scan::D) {
            transform.velocity.set(std::clamp(transform.velocity.x() + (1 * is_press), -1.f, 1.f), transform.velocity.y());
        }

        // Left
        if (scancode == sf::Keyboard::Scan::A) {
            transform.velocity.set(std::clamp(transform.velocity.x() - (1 * is_press), -1.f, 1.f), transform.velocity.y());
        }
    }
}