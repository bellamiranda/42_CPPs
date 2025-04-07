#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	if (point == a || point == b || point == c)//if it is in one of the vertex
		return false;
	
	Fixed areaABC = a.area(a, b, c);

	Fixed areaPAB = point.area(point, a, b);
	Fixed areaPAC = point.area(point, a, c);
	Fixed areaPBC = point.area(point, b, c);
	//std::cout << "total area = " << areaABC << std::endl;
	//std::cout << "sum 3 areas = " << areaPAB + areaPAC + areaPBC << std::endl;
	if (areaPAB != 0 && areaPAC != 0 && areaPBC != 0) { //if not on edge
		if (areaABC == (areaPAB + areaPAC + areaPBC))
			return true;
	}
	return false;
}

/* 
ALGORITHM: Using barycentric coordinates
1- calculate the area of the triangle
2- calculate 3 areas - PAB, PAC and PBC
3- if point is inside -> sum of small triangles = big triangle
	if the sum is bigger than the total area -> point is out of the triangle
	the area is 0 if the point is in one of the edges
*/