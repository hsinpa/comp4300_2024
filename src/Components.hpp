//
// Created by Hsinpa on 2024/10/4.
//

#ifndef COMP4300_COMPONENTS_HPP
#define COMP4300_COMPONENTS_HPP
#include <SFML/Graphics.hpp>
#include "utility/Vec2.hpp"

struct CMovableComponent {
    float speed = 1;

    CMovableComponent() = default;
    CMovableComponent(float p_speed): speed(p_speed) {}
};

struct CTransform {
    Vec2f pos = {0.0, 0.0};
    Vec2f velocity = {0.0, 0.0};
    float angle = 0;
    float angular_velocity = 0;

    CTransform() = default;

    CTransform(const Vec2f & p, const Vec2f & v, float a, float av):
    pos(p), velocity(v), angle(a), angular_velocity(av) {}
};

struct CShape {
    sf::CircleShape circle;

    CShape() = default;
    CShape(float radius, size_t points, const sf::Color & fill, const sf::Color & outline, const float& thickness) {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(radius, radius);
        circle.setPointCount(points);
        circle.setRadius(radius);
    }
};

class CCollision {
public:
    float radius = 0;
    CCollision() = default;
    CCollision(float r): radius(r) {}
};

struct CScore {
    int score = 0;

    CScore() = default;
    CScore(int s): score(s) {}
};

struct CLifespan {
    int lifespan = 0;
    int remaining = 0;
    CLifespan() = default;
    CLifespan(int totalLifespan): lifespan(totalLifespan), remaining(totalLifespan) {}
};

struct CInput {
    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;
    bool shoot = false;

    CInput() = default;
};


#endif //COMP4300_COMPONENTS_HPP
