//
// Created by hsinp on 2024/10/03.
//

#ifndef VEC_H
#define VEC_H
#include <type_traits>

template <class T>
concept is_numeric = std::is_arithmetic_v<T>;

template <is_numeric T>
class Vec2 {
    T _x;
    T _y;

public:
    Vec2() : _x(0), _y(0){}
    Vec2(T p_x, T p_y) : _x(p_x), _y(p_y) {}


    T & x()       { return _x; }
    T & y()       { return _y; }

    void operator+(Vec2 const& rh);
    void operator-(Vec2 const& rh);
    void operator*(Vec2 const& rh);
    void operator/(Vec2 const& rh);

    T distance();
};

#endif //VEC_H
