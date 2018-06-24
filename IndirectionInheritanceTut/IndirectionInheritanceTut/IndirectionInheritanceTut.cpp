#pragma once
#include"Person.h"
#include"Tweeter.h"

int main()
{
	Person JDoe("John", "Doe", 332244);
	Person & rJDoe = JDoe;
	Person* pJDoe = &JDoe;

	Tweeter JDoo("John", "Doo", 445566, "Johnny DOO");
	Person* pJDoo = &JDoo;
	Person & rpJDoo = JDoo;
	Tweeter & rtJDoo = JDoo;

	//Output of the following lines differs depending on whether GetName() is virtual or not

	std::cout << "JDoe.GetName()" << std::endl;
	std::cout << JDoe.GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "rJDoe.GetName()" << std::endl;
	std::cout << rJDoe.GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "pJDoe->GetName()" << std::endl;
	std::cout << pJDoe->GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "JDoo.GetName()" << std::endl;
	std::cout << JDoo.GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "pJDoo->GetName()" << std::endl;
	std::cout << pJDoo->GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "rpJDoo.GetName()" << std::endl;
	std::cout << rpJDoo.GetName() << std::endl;
	std::cout << "" << std::endl;
	std::cout << "rtJDoo.GetName()" << std::endl;
	std::cout << rtJDoo.GetName() << std::endl;

	//If you mark a function as virtual, you need to mark the destructor as virtual also. That's because in the following example errors arise.
	Person* someone = new Tweeter("Some", "One", 23222, "Annonymous");
	std::cout << "someone->GetName()" << std::endl;
	std::cout << someone->GetName() << std::endl;
	delete someone;
	//Unless you mark the base class (Person) destructor as virtual, the tweeter destructor will never run, and we will have a memory leak.
}