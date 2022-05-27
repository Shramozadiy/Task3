
#include <iostream>

#include "GCode.h"
#include "Point.h"



int main()
{
	Point P;
	Point newP;
	GCode code;

	// Начальная позиция
	std::cout << "Initial coordinates: ";
	std::cin >> P;
	
	// Добавляем команды, пока не отправили 0
	std::string str;
	while (std::getline(std::cin, str))
	{
		if (str == "0")
			break;
		code.addCodeLine(str);
	}

	// Вывод результата 
	if (code.runCode(newP, P))
	{
		newP.output();
	}
	else
	{
		newP.output();
		std::cout << std::endl << "ERROR SCRIPT";
	}

	return 0;
}