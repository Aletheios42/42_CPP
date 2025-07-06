#include "../Inc/Point.hpp"

Point::Point() : _x(0), _y(0) {
    std::cout << "Default constructor called" << std::endl;
}

Point::Point(float x, float y) : _x(x), _y(y) {
    std::cout << "Parametrized constructor called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
    std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
    std::cout << "Assignment operator called" << std::endl;
    // No-op, const members can't be assigned
    return *this;
}

Point::~Point() {
    std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }

static Fixed vectorProduct(Point const& A, Point const& B, Point const& P) {
    Fixed abx = B.getX() - A.getX();
    Fixed aby = B.getY() - A.getY();
    Fixed apx = P.getX() - A.getX();
    Fixed apy = P.getY() - A.getY();

    return abx * apy - aby * apx;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed s1 = vectorProduct(a, b, point);
    Fixed s2 = vectorProduct(b, c, point);
    Fixed s3 = vectorProduct(c, a, point);

    if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
        return false;

    return (s1 > Fixed(0) && s2 > Fixed(0) && s3 > Fixed(0)) ||
           (s1 < Fixed(0) && s2 < Fixed(0) && s3 < Fixed(0));
}

