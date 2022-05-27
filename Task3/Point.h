#pragma once

#include <iostream>

class Point
{
public:

	Point();

	Point(int x, int y, int z);

	Point operator+(const Point& a);

	void output();

	friend std::istream& operator>>(std::istream& is, Point& point);

private:
	int x = 0;
	int y = 0;
	int z = 0;
};