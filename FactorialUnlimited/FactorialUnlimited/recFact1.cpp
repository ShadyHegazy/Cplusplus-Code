#include <iostream>
#include <vector>
#include<string>
std::string multiplyBig(std::string largeNum, int smallNum)
{
	std::vector<std::string> multSheet;
	multSheet.assign(smallNum, largeNum);
	//strLargeNum=std::to_string(largeNum);
	int largeLoop = largeNum.length();
	std::vector<int> rawSum;
	std::string strTempSum;
	int tempSum;
	for (int i = largeLoop - 1; i > -1; --i)
	{
		strTempSum = largeNum.at(i);
		tempSum = std::stoi(strTempSum) * smallNum;
		rawSum.insert(rawSum.begin(), tempSum);
	}
	//consider using string.at instead of [] if things go wrong
	std::string result = "";
	int carry = 0;
	int tempNum;
	std::string strCarry;
	int bigLoop = largeNum.length();
	for (int j = bigLoop - 1; j > -1; --j)
	{
		tempNum = rawSum[j] + carry;
		if (tempNum < 10)
		{
			result = std::to_string(tempNum) + result;
			carry = 0;
		}
		else
		{
			carry = 0;
			strCarry = std::to_string(tempNum);
			result = strCarry.back() + result;
			strCarry.pop_back();
			carry = std::stoi(strCarry);
		}
	}
	if (carry != 0)
	{
		result= std::to_string(carry)  + result;
	}
	return result;
};

unsigned long long factorialRecursive(int y)
{
    if (y>1)
    {
        return y*factorialRecursive(y-1);
    } 
    else if (y==1 or y==0)
    {
        return 1;
    }
    else
    {
        std::cout << "Invalid number" << std::endl;
        return 0;
    }
};

int main()
{
    int initNum;
    std::cout << "Enter the number that you want to calculate its factorial ...";
    std::cin >> initNum;
	std::string strFactResult;
	std::string tempResult=std::to_string(factorialRecursive(20));;
    for (int i = 0; i<100; ++i)
    {
        if (initNum < 0)
        {
            std::cout << "Invalid number. Please enter a positive number." << std::endl;
            std::cin >> initNum;
        }
		else if (initNum >20)
		{
			for (int k=21; k<=initNum; ++k)
			{
				strFactResult= multiplyBig(tempResult,k);
				tempResult=strFactResult;
			}
			break;
		}
		else 
        {
             strFactResult=std::to_string(factorialRecursive(initNum));
             break;
        }
    }
	std::cout << "The factorial for the number you entered is:  " << strFactResult << std::endl;
	return 0;
}