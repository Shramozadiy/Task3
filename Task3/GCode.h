#pragma once

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

#include "Point.h"

class GCode
{
public:

	void addCodeLine(std::string str);

	bool isCodeCorrect(std::string str);

	bool runCode(Point& newP, Point& P);

private:

	std::vector <std::string> code_;
};