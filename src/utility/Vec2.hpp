//
// Created by hsinp on 2024/10/03.
//

#ifndef VEC_H
#define VEC_H
#include <type_traits>
#include <cmath>

template <class T>
concept is_numeric = std::is_arithmetic_v<T>;

template <is_numeric T>
class Vec2 {
    T _x = 0;
    T _y = 0;

public:
    Vec2() = default;
    Vec2(T p_x, T p_y) : _x(p_x), _y(p_y) {}

    T x() const    { return _x; }
    T y() const    { return _y; }

    Vec2 operator+(const Vec2& rh) {
        return Vec2(_x + rh.x(), _y + rh.y());
    }

    Vec2 operator-(const Vec2& rh) {
        return Vec2(_x - rh.x(), _y - rh.y());
    }

    Vec2 operator*(const Vec2& rh) {
        return Vec2(_x * rh.x(), _y * rh.y());
    }

    Vec2 operator/(const Vec2& rh) {
        return Vec2(_x / rh.x(), _y / rh.y());
    }

    Vec2 operator*(const T& rh) {
        return Vec2(_x * rh, _y * rh);
    }

    Vec2 operator/(const T& rh) {
        return Vec2(_x / rh, _y / rh);
    }

    T length() {
        return static_cast<T>(sqrt((_x * _x) + (_y * _y)));
    }

    void normalize() {
        T mag = length();

        _x = static_cast<T>(_x / mag);
        _y = static_cast<T>(_y / mag);
    }

    void set(T x, T y) {
        _x = x;
        _y = y;
    }
};

using Vec2f = Vec2<float>;
#endif //VEC_H
