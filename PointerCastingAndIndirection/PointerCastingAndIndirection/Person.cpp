#pragma once
#include "Person.h"

using namespace std;

Person::Person(string first,string last,
	int arbitrary) : firstname(first),lastname(last),
	arbitrarynumber(arbitrary) //, pResource(nullptr) no need for initiating pResource because sharedptr code does it for us
{
}

 Person::~Person()
{
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}

//void Person::addResource()
//{
//	pResource.reset();
//	pResource = std::make_shared<Resource>("Resource for " + GetName());
	//pResource = new Resource("Resource for " + GetName());
//}

//Person::Person(Person const & p)
//{
//	pResource = new Resource(p.pResource->GetName());
//}
//
//Person& Person::operator=(const Person& p)
//{
//	delete pResource;
//	pResource = new Resource(p.pResource->GetName());
//	return *this;
//}
//no need for the above code because we are using smart pointers not raw pointers
//sharedptr will take care of all these issues
