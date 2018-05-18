#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "This program compares two words to tell which is longer." << endl;
	bool userchoice = true;

	string firstinput;
	string firstwrd;
	string secondwrd;
	string secondinput;

	while (userchoice == true)
	{
		cin.clear();
		cout << "Enter the first word please! ... " << endl;
		//cin >> firstinput;
		getline(cin, firstinput);
		cin.clear();
		int fif = firstinput.find(' ');
		cout << "you entered: " << firstinput << endl;
		firstwrd = firstinput.substr(0, fif);
		cout << "The first word is " << firstwrd << endl;

		cout << "Thanks!" << endl << "Now enter the second word ..." << endl;
		//cin >> secondinput;
		getline(cin, secondinput);
		cin.clear();
		int sif = secondinput.find(' ');
		cout << "you entered: " << secondinput << endl;
		secondwrd = secondinput.substr(0, sif);
		cout << "The second word is " << secondwrd << endl;

		int firstwrdlen = firstwrd.length();
		int secondwrdlen = secondwrd.length();

		if (firstwrdlen > secondwrdlen)
		{
			cout << "The first word \"" << firstwrd << "\" is longer, with a length of " << firstwrdlen << " characters. " << endl << endl;
		}

		if (firstwrdlen < secondwrdlen)
		{
			cout << "The second word \"" << secondwrd << "\" is longer, with a length of " << secondwrdlen << " characters. " << endl << endl;
		}

		if (firstwrdlen == secondwrdlen)
		{
			cout << "Bro! This is confusing!" << endl << "Both are of the same length!" << endl << endl;
		}

		bool userinputcorrect;
		userinputcorrect = false;
		string choice;
		string cinput;

		while (userinputcorrect == false)
		{
			cout << "Do you need me to do more comparisons? (y/n)" << endl;
			//cin >> choice;
			getline(cin, cinput);
			cin.clear();
			int cif = cinput.find(' ');
			choice = cinput.substr(0, cif);

			if (choice == "n")
			{
				userchoice = false;
				userinputcorrect = true;
			}

			else if (choice == "y")
			{
				cin.clear(); 
				userchoice = true;
				userinputcorrect = true;

			}

			else
			{
				cout << "Invalid input! I will ask the question again. Please enter \"y\" for more comparisons or \"n\" for terminating the program!" << endl;
				userinputcorrect = false;
			}
		}
	}

	return 0;
}