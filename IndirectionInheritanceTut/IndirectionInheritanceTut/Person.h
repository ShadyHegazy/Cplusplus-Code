#pragma once
#include <string>
#include<iostream>
#include<memory>


class Person
{
private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	//Resource* pResource;
	/*std::shared_ptr<Resource> pResource;*/

public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	virtual ~Person();
	//Person(Person const & p);
	//Person& operator=(const Person& p);
	virtual std::string GetName() const;
	int GetNumber() const {return arbitrarynumber;}
	void SetNumber(int number) { arbitrarynumber = number; };
	void SetFirstName(std::string first) { firstname = first; }
	//void addResource();
	//std::string GetResourceName() const { return pResource ? pResource->GetName() : "pResource is not pointing anywhere"; }
};
