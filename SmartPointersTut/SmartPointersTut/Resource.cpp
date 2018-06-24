#pragma once
#include "Resource.h"

Resource::Resource(std::string n) : name(n)
{
	std::cout << "Constructing" << std::endl;
}

Resource::~Resource(void)
{
	std::cout << "Destucting" << std::endl;
}
