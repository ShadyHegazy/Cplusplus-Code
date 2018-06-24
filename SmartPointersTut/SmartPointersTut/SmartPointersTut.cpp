#pragma once
#include "Person.h"

std::string Dummy(Person const p)
{
	return p.GetResourceName();
}

int main()
{
	{
		Person JDoe("John", "Doe", 123);
		JDoe.addResource();
		std::string s1 = JDoe.GetResourceName();
		JDoe.addResource();

		Person JDoeDoe = JDoe;
		JDoe = JDoeDoe;

		std::string s2 = Dummy(JDoe);
		//Now we have 3 strong references but they will be all automatically cleared by the sharedptr code after going out of scope
	}
	return 0;
	
}
