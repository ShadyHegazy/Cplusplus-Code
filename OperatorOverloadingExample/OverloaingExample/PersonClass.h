#pragma once
#include <string>

class Person
{
private:
	std::string fName;
	std::string lName;
	int aNumber;
	
	friend bool operator<( int i , Person const& p);

public:
	Person(std::string fname, std::string lname, int anumber);
	~Person();
	std::string getName() const;
	int getNumber() const { return aNumber; };
	void setNumeber(int number) { aNumber = number; };
	bool operator<(Person const& p) const;
	bool operator<(int i) const;
};

