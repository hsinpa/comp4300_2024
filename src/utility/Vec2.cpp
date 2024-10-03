//
// Created by hsinp on 2024/10/03.
//

#include "Vec2.h"

#include <cmath>

template <is_numeric T>
T Vec2<T>::distance() {
    return static_cast<T>(sqrt((x * x) + (y * y)));
}

template <is_numeric T>
void Vec2<T>::operator*(Vec2 const& rh) {
    _x *= rh.x;
    _y *= rh.y;
}

template <is_numeric T>
void Vec2<T>::operator/(Vec2 const& rh) {
    _x /= rh.x;
    _y /= rh.y;
}

template <is_numeric T>
void Vec2<T>::operator-(Vec2 const& rh) {
    _x -= rh.x;
    _y -= rh.y;
}

template <is_numeric T>
void Vec2<T>::operator+(Vec2 const& rh) {
    _x += rh.x;
    _y += rh.y;
}