#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std:endl;
}

Point::Point(const float a, const float b) : _x(a), _y(b) {
	//std::cout << "Parameters constructor called" << std::endl;
}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	//std::cout << "Destructor called" << std::endl;
}

//-------------------------------------------------------------------------------

Point& Point::operator=(const Point &src) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		(Fixed)this->_x = src._x;
		(Fixed)this->_y = src._y;
	}
	return *this;
}

bool Point::operator==(const Point &src) const {
	return (this->getX() == src.getX() && this->getY() == src.getY());
}

std::ostream& operator<<(std::ostream &output, const Point &point) {
	output << "(" << point.getX() << ", " << point.getY() << ")";
	return output;
}

//-------------------------------------------------------------------------------

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;	
}

//area = 1/2 * |(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))|
Fixed Point::area(Point const a, Point const b, Point const c) const {
	Fixed area;
	area = ((a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() * (a.getY() - b.getY())) / 2);
	if (area < 0)
		return area * (-1);
	return area;
}
