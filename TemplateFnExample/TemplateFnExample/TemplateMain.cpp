#pragma once
#include "BankAccount.h"
#include "Person.h"
#include <string>
#include <iostream>

template <class T>
T max(T const& t1, T const& t2)
{
	return t1 < t2 ? t2 : t1;
}

int main()
{
	std::cout << "Max of 33 and 44 is " << max(33, 44) << std::endl;
	std::string s1 = "Hello";
	std::string s2 = "Wprld";
	std::cout << "Max of " << s1 << " and " << s2 << " is " << max(s1, s2) << std::endl;
	Person p1("John", "Doe", 1000);
	Person p2("Imaginary", "Person", 0);
	std::cout << "Max of " << p1.GetName() << " and " << p2.GetName() << " is " << max(p1, p2).GetName() << std::endl;
}