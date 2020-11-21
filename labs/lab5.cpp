#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getter();
//global values to make getter function easier
float A, B, a0, a1;

int main()
{
	cout << "Evan Miller \nCS250 \nLab 5 " << endl;
	//loop for program repetition
	for(int i = 0; i < 4; i++)
	{
		//get values
		getter();
		//calc discriminant 
		float dis = (-A)*-(A)-4*(-B);     //roots of the homog eq sub'd into the quad eq.
		if(dis < 0)
		{
			cout << "The relation has a complex root...moving to next sequence..." << endl;
		}
		else
		{
			float x1, x2, C, D;
			x1 = (A + sqrt(dis))/2;
			x2 = (A- sqrt(dis))/2;
		
		//cal recurrence solutions
			//if a0 = C
			if(x1 == x2)
			{
				C = a0;
				D = a1/x1 - C;
				cout << "Solution: (" << C << " + n*" << D << ") * " << x1 << "^n" << endl;
				cout << "The first six terms of the sequence: " << flush;
				for(int i = 0; i < 6; i++)
				{
					cout << " " << (C + i*D) * pow(x1,i);
				}
				cout << endl;
			}
			//if a0 = C + D
			else
			{
				C = (a0 * x2 - a1)/(x2 - x1);
				D = (a0 * x1 - a1)/(x1 - x2);
				cout << "Solution: " << C << " * " << x1 << "^n + " << D << " * " << x2 << "^n" << endl;
				cout << "The first six terms of the sequence: " << flush;
				for(int i = 0; i < 6; i++)
				{
					cout << " " << C*pow(x1,i) + D*pow(x2,i);
				}
			cout << endl;
			}
		}
	cout << endl;
	}
	return 0;
}
void getter()
{
	cout << "Please enter your A value: " << flush;
	cin >> A;
	cout << "\nPlease enter your B value: " << flush;
	cin >> B;
	cout << "\nPlease enter your a0 value: " << flush;
	cin >> a0;
	cout << "\nPlease enter your a1 value: " << flush;
	cin >> a1;
	cout << "\nThank you, your values are: " << A << ", " << B << ", ";
	cout << a0 << ", " << a1 << " respectively." << endl;	
}
