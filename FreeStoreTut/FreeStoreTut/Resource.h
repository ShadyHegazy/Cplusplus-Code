#pragma once
#include <iostream>
#include <string>


class Resource
{
private:
	std::string name;

public:
	Resource(std::string n);
	~Resource(void);
	std::string getName() const { return name; }
};