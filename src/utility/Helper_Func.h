//
// Created by Hsinpa on 2024/10/7.
//

#ifndef COMP4300_HELPER_FUNC_H
#define COMP4300_HELPER_FUNC_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "entt.hpp"
#include "Vec2.hpp"
#include "../Entities.h"

class Helper_Func {
public:
    static void Register_Bullet(std::unique_ptr<entt::registry>& entt_registry, Vec2f& position, Vec2f direction,
                                Identity identity);
};


#endif //COMP4300_HELPER_FUNC_H
