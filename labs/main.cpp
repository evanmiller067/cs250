/*
NAME: Evan Miller
ASSIGNMENT: Lab 1
SOURCES: None
*/

#include <iostream>

using namespace std;
char premise(bool P, bool Q, bool R)
{
	//change here
	if(((P || Q) && (!Q || R)) && (!Q && P) && ((!R || Q) || P))
	{
		cout << "T";
	}
	else
	{
		cout << "F";
	}
}
char conclusion(bool P, bool Q, bool R)
{
	// Change here
	if(!Q && R)
	{
		cout << "T";
	}
	else
	{
		cout << "F";
	}
}
void printer()
{
	int rowIndex = 0;
	bool P = true,Q = true, R = true;
	cout << "Row	P	Q	R	Prem	Concl" << endl;
	
	for(int i = 0; i < 8; i++)
	{
		cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
		
		
	}
}
int main()
{
	cout << "Evan Miller \n Lab 1" << endl;
	printer();
return 0;
}
