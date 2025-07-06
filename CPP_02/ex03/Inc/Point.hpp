#pragma once

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(float x, float y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed vectorProduc(Fixed x, Fixed y);
