#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(const float a, const float b);
	Point(const Point& src);
	~Point();

	Point& operator=(const Point &src);
	bool operator==(const Point &src) const;

	Fixed getX() const;
	Fixed getY() const;
	Fixed area(Point const a, Point const b, Point const c) const;
};

std::ostream& operator<<(std::ostream&, const Point&);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif