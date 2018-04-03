#include <iostream>
using namespace std;
int main()
{
	int answer = 7;
	int inpt=0;
	
	while (inpt != answer)
	{
		cout << "Give a guess ..." << endl;
		cin >> inpt;
		if (inpt < answer)
			cout << "your guess is too low!" << endl;
		if (inpt > answer)
			cout << "yout guess is too high!" << endl;
	}
	cout << "you guessed correctly!";
	return 0;
}