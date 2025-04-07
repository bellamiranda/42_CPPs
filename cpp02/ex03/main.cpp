#include "Point.hpp"

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(2.0f, 0.0f);
	Point c(0.0f, 2.0f);

	Point check(1.0f, 1.0f);
	Point check1(0.5f, 0.5f);

	bool inside = bsp(a, b, c, check);
	std::cout << "the point " << check << " is inside the triangle formed by ";
	std::cout << a << ", " << b << " and " << c << "?" << std::endl;
	std::cout << "answer = " << inside << std::endl;

	bool inside1 = bsp(a, b, c, check1);
	std::cout << "the point " << check1 << " is inside the triangle formed by ";
	std::cout << a << ", " << b << " and " << c << "?" << std::endl;
	std::cout << "answer = " << inside1 << std::endl;
}