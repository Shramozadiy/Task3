

#include "GCode.h"



void GCode::addCodeLine(std::string str)
{
	code_.push_back(str);
}

bool GCode::isCodeCorrect(std::string str)
{
	std::regex regular(R"(X-?\d+;Y-?\d+;Z-?\d+;)");
	return std::regex_match(str, regular);
}

bool GCode::runCode(Point& newP, Point& P)
{
	newP = P;

	std::regex regular(R"(-?\d+)");
	std::smatch m;

	for (auto& i : code_)
	{
		if (isCodeCorrect(i))
		{
			int buf[3] = {};
			std::string str = i;
			int j = 0;
			while (std::regex_search(str, m, regular))
			{
				buf[j++] = std::stoi(m[0].str());
				str = m.suffix();
			}
			Point change = { buf[0],  buf[1], buf[2] };
			newP = newP + change;
		}
		else
		{
			return 0;
		}
	}

	return 1;
}