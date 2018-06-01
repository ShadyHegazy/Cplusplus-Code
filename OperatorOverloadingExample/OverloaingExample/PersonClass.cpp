
#pragma once
#include "PersonClass.h"
using std::string;

Person::Person(string fname, string lname, int anumber) :
	fName(fname), lName(lname), aNumber(anumber)
{
}

Person::~Person()
{
}

string Person::getName() const
{
	return fName + " " + lName;
}

bool Person::operator<(Person const& p) const
{
	return aNumber < p.aNumber;
}

bool Person::operator<(int i) const
{
	return aNumber < i;
}

bool operator<(int i , Person const& p)
{
	return i < p.getNumber();
}