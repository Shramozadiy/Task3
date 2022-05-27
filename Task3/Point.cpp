

#include "Point.h"



Point::Point() {};

Point::Point(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point Point::operator+(const Point& a)
{
	Point point = { this->x + a.x, this->y + a.y, this->z + a.z };
	return point;
}

void Point::output()
{
	std::cout << x << " " << y << " " << z;
}

std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}