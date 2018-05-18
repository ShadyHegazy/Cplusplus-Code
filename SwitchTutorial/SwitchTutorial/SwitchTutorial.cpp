// SwitchTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int x;
	std::cout << "Enter a number, 0 or negative to quit ..." << std::endl;
	std::cin >> x;
	while (x > 0)
	{
		switch (x)
		{
		//case 1 will function normally
		case 1:
			std::cout << "You entered 1 " << std::endl;
			break;
		//case 2 and 3 lead to the same action as 2 falls through to 3
		case 2:
		case 3:
			std::cout << "You entered 2 or 3" << std::endl;
			break;
		//In case 4 the actions for both 4 and 5 will be executed because we ommitted the "break;" between them
		case 4:
			std::cout << "You entered 4" << std::endl;
		case 5: 
			std::cout << "You entered 5" << std::endl;
			break;
		default:
			std::cout << "You entered a number other than 1, 2, 3, 4, and 5. Try again!!" << std::endl;
		}
		std::cout << "Enter a number, 0 or negative to quit ..." << std::endl;
		std::cin >> x;
	}
    return 0;
}

