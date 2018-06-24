#pragma once
#include"Resource.h"

int main()
{
	{
		Resource localResource("That's a local resource");
		std::string localString = localResource.getName();
	}

	Resource* pResource = new Resource("Free-store resource");
	std::string freeStoreString = pResource->getName();

	Resource* p2 = pResource;

	int j = 3;
	delete pResource;
	
	//It is a good practice to set a pointer to null after deleting it, so that you have a more understanable error if someone else used it.
	pResource = nullptr;

	//The below line will trigger an error bcz it is calling a method from a deleted pointer
	std::string fakeString = pResource->getName();
	std::string fakeString2 = p2->getName();

	return 0;
}
