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
		return 'T';
	}
	else
	{
		return 'F';
	}
}
char conclusion(bool P, bool Q, bool R)
{
	// Change here
	if(!Q && R)
	{
		return 'T';
	}
	else
	{
		return 'F';
	}
}
void printer()//Print out truth table and updated bool values for prem/concl functions
{
	//Messy and clunky, but less loops and if statements than if I made it pretty. sorry.
	cout << "Row	P	Q	R	Prem	Concl" << endl;

	int rowIndex = 0;
	bool P = true,Q = true, R = true;
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = true,Q = true, R = false;
	rowIndex = 1;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = true,Q = false, R = true;
	rowIndex = 2;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = true,Q = false, R = false;
	rowIndex = 3;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = false,Q = true, R = true;
	rowIndex = 4;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = false,Q = true, R = false;
	rowIndex = 5;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = false,Q = false, R = true;
	rowIndex = 6;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
	
	P = false,Q = false, R = false;			
	rowIndex = 7;	
	cout << rowIndex << "       " << P << "       " << Q << "       " << R << "        " << premise(P,Q,R) << "       " << conclusion(P,Q,R) << endl;
}
int main()
{
	cout << "Evan Miller \n Lab 1" << endl;
	printer();
return 0;
}
