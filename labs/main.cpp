/*
NAME: Evan Miller
ASSIGNMENT: Lab 1
SOURCES: None
*/

#include <iostream>

using namespace std;

bool premise(bool P, bool Q, bool R)
{
	//change here
	return ((P || Q) && (!Q || R)) && (!Q && P) && ((!R || Q) || P);
}
bool conclusion(bool P, bool Q, bool R)
{
	// Change here
	return (!Q && R);
}
void matrix()
{
	int rowIndex = 0;
	char P = 'T', Q = 'T', R = 'T';
	cout << "Row	P	Q	R	Prem	Concl" << endl;
	
	for(int i = 0; i < 8; i++)
	{
		cout << rowIndex << "	" << P << "   " << Q << "	" << R << "   " << premise(P,Q,R) < "	" << conclusion(P,Q,R) << endl;
		
	}

	
}
int main()
{
	cout << "Evan Miller \n Lab 1" << endl;
	
return 0;
}
