/*
NAME: Evan Miller
ASSIGNMENT: Lab 2
SOURCES:
https://www.geeksforgeeks.org/how-to-return-multiple-values-from-a-function-in-c-or-cpp/
https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
*/

#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int excOR(int a, int b)
{
	return (a && !b) || (!a && b);
}
pair<int, int> halfAdder(int a, int b)
{
	return std::make_pair(excOR(a,b), a && b);
}
pair<int, int> fullAdder(int a, int b, int c)
{
	int s0 = 0, s1 = 0, c0 = 0, c1 = 0; //sums and carry
	std::tie(s0, c0) = halfAdder(a,b);
	std::tie(s1, c1) = halfAdder(s0,c);
	
	return std::make_pair(s1, c0 || c1);
}
string compute(string A, string B)
{
	int a = 0, b = 0, c = 0, sum = 0, carry = 0;
	string result;

	for(int i = 0; i < A.length(); i++)
	{	
		a = A.at(i) - '0', b = B.at(i) - '0';
		std::tie(sum, carry) = fullAdder(a,b,c);

		cout << "The bits are " << a << " and " << b << ". " << flush;
		cout << "The carry in is " << c << ". " << flush;
		cout << "The sum is " << sum << ". " << flush;
		cout << "The carry out is " << carry << ". " << endl;

		if((i + 1) % 4 == 0)
		{
			result.insert(0, " ");
		}
		result.insert(0, std::to_string(sum));
		c = carry;
	}
	if(carry == 1)
	{
		result.insert(0, std::to_string(carry) + " ");
	}
	cout << "The answer is " << flush;
	return result;
}
int main()
{
	cout << "Evan Miller \nLab 2 \nCS250" << endl;
	
	for(int i = 0; i < 4; i++)
	{
		cout << "cycle " << i << " of 3 starting: " << endl;
		string inputA, inputB;
		cout << "Input one: " << flush;
		cin >> inputA;
		cout << "\nInput Two: " << flush;
		cin >> inputB;
		cout << "The numbers to be added are " << inputA << " and " << inputB << endl;
		cout << compute(inputA, inputB) << endl;
	}
return 0;
}
