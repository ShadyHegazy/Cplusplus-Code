#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> vi;

	for (int i=0; i < 10; i++)
	{
		vi.push_back(i);
	}

	for (auto item : vi)
	{
		cout << item << " ";
	}

	cout << endl;

	vector <string> vs;

	cout << "Enter three words ..." << endl;

	for (int i=0; i < 3; i++)
	{
		string s;
		cin >> s;
		vs.push_back(s);
	}

	for (auto word : vs)
	{
		cout << word << " ";
	}

	cout << endl;

	cout << "int vector vi has " << vi.size() << " elements." << endl;

	vi[5] = 3;
	vi[6] = -1;

	for (auto item : vi)
	{
		cout << item << " ";
	}
	cout << endl;

	for (unsigned int i=0; i < vi.size(); i++)
	{
		cout << vi[i] << " ";
	}
	cout << endl;

	for (auto i = begin(vi); i != end(vi); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	sort(begin(vi), end(vi));

	for (auto item : vi)
	{
		cout << item << " ";
	}
	cout << endl;

	sort(begin(vs), end(vs));

	for (auto item : vs)
	{
		cout << item << " ";
	}
	cout << endl;

	int  threes = count(begin(vi), end(vi), 3);
	cout << "Vector of ints has " << threes << " elements with value 3." << endl;

	int tees = count(begin(vs[0]), end(vs[0]), 't');
	cout << "First word has " << tees << " letter t's" << endl;

	return 0;
}