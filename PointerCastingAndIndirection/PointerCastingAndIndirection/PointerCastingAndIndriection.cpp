#include"Person.h"
#include "Resource.h"
#include "Tweeter.h"


int main()
{
	Tweeter t("Anonymous1", "Anonymous2", 223344, "@gmail.com");
	Person* perPtr = &t;
	//The line below has an error because it is trying to initiate a Tweeter instance (twPtr) with a Person object (perPtr) 
	//Tweeter* twPtr = perPtr;
	//We can solve that using c-style casting, which is dangerous
	//Tweeter* twPtr = (Tweeter*)perPtr;
	//But this isn't safe at all. So, the better way is to use static casting (because we already 
	//know for sure that perPtr is pointing to a tweeter object t. So we will use it as shown below:
	Tweeter* twPtr = static_cast<Tweeter*>(perPtr);
	std::cout << twPtr->GetName() << std::endl;
	//Using static casting will enable the compiler to protect u against some mistakes like the one below:
	//int i = 3;
	//Tweeter* twPi = static_cast<Tweeter*>(i);
	//It gives compiler errors. However, if u used c-style cast or a reinterpret_cast, it would pass. But with the cost of a runtime error which will make the user unhappy
	
	//Manytimes, you will not be able to know for sure what a pointer is pointing at in advance. So, static casting will not be the best choice. But dynamic casting can be better in these cases.
	//It happens in sophisticated applications where there are a lot of user input.

	Resource r("local");
	Tweeter* twPtr2;
	std::cout << "Use Resource or Tweeter? r/t" << std::endl;
	std::string answer;
	std::cin >> answer;
	if (answer == "r")
	{
		//Resource and Tweeter are unrelated -no inheritance or polymorphism- so the pointer will end up being a null pointer
		twPtr2 = dynamic_cast<Tweeter*>(&r);
	}
	else 
	{
		twPtr2 = dynamic_cast<Tweeter*>(perPtr);
	}
	if (twPtr2)
	{
		std::cout << "twPtr2->GetName()" << std::endl;
		std::cout << twPtr2->GetName() << std::endl;
		std::cout << "Dynamic Casting succeeded as per the above line" << std::endl;
	}
	else
	{
		std::cout << "Pointer can't be cast to a Tweeter. " << std::endl;
	}
}