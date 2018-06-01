#pragma once
#include "Person.h"
#include <string>
#include <iostream>
#include "AccumClass.h"

int main()
{
	//In c++17, no need to specify the type when initiating an object of a template class. 
	//It automatically figures it out from the type of the initial value.
	Accum<int> integers(0);
	integers += 3;
	integers += 4;
	std::cout << integers.GetTotal() << std::endl;

	Accum<std::string> strings("");
	strings += "Hello!";
	strings += " World.";
	std::cout << strings.GetTotal() << std::endl;

	Accum<Person> people(0);
	Person p1("P1first", "P1last", 15);
	Person p2("P2first", "P2last", 25);
	people += p1;
	people += p2;
	std::cout << people.GetTotal() << std::endl;

	return 0;
}