#pragma once
#include"Person.h"
#include"Tweeter.h"

int Dummy(Person const& p) { return p.GetNumber(); }
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
	std::cout << "" << std::endl;


	//If you mark a function as virtual, you need to mark the destructor as virtual also. That's because in the following example errors arise.
	//Person* someone = new Tweeter("Some", "One", 23222, "Annonymous");
	//std::cout << "someone->GetName()" << std::endl;
	//std::cout << someone->GetName() << std::endl;
	//delete someone;
	//Unless you mark the base class (Person) destructor as virtual, the tweeter destructor will never run, and we will have a memory leak.

	//The following lines will use pointers and references to avoid slicing
	std::shared_ptr<Person> spJDoe = std::make_shared<Tweeter>("So ", "What", 2018, "What what?");
	std::cout << "spJDoe->GetName()" << std::endl;
	std::cout << spJDoe->GetName() << std::endl;
	std::cout << "" << std::endl;

	//JDoo = JDoe;
	//This can't happen simply because the = operator won't find where to get twitterhandle from Person. You can write an operator overload to get over that if u need, but it is not given naturally from the compiler.


	//Copying a Tweeter to a person
	JDoe = JDoo;
	//Can happen, because the twitter handle will be sliced and the compiler will be happy
	std::cout << "JDoe.GetName()" << std::endl;
	std::cout << JDoe.GetName() << std::endl;
	std::cout << "" << std::endl;

	//Here we test a function that takes Person as a parameter. It returns an int retreived through a function that is overwritten in the derived class
	//The function should return 0 if it used the Tweeter version of the GetNumber function, and arbitraryNumber if it used the Person version.
	//What happens is: the function uses the Person version even if the GetNumber function is virtual, as long as it takes Person by value.
	//To make it apply polymorphism, we need to make it take Person by reference
	//The output will differ with const& and without it.
	int x;
	x = Dummy(JDoe);
	std::cout << "x = Dummy(JDoe)" << std::endl;
	std::cout << x << std::endl;
	std::cout << "" << std::endl;

	x = Dummy(JDoo);
	std::cout << "x = Dummy(JDoo)" << std::endl;
	std::cout << x << std::endl;
	std::cout << "" << std::endl;



}