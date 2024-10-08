//
// Created by Hsinpa on 2024/10/7.
//
#include <SFML/Graphics.hpp>
#include "entt.hpp"
#include "Vec2.hpp"
#include "Helper_Func.h"
#include "../Components.hpp"
#include "../Entities.h"

void Helper_Func::Register_Bullet(std::unique_ptr<entt::registry> &entt_registry, Vec2f &position, Vec2f direction,
                                  Identity identity) {
    const auto entity = entt_registry->create();
    entt_registry->emplace<CProjectile>(entity, identity);
    entt_registry->emplace<CMovableComponent>(entity, 600);
    entt_registry->emplace<CTransform>(entity, position, direction, 0, 100);
    entt_registry->emplace<CShape>(entity, 10, 12, sf::Color::Red, sf::Color::White, 1);
}

float Helper_Func::random_range(unsigned int max_range) {
    auto r = ((double) rand() / (RAND_MAX)) + max_range;
    return static_cast<float>(r);
}