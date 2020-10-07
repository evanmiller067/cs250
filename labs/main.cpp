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
	if(((P || Q) && (!Q || R)) && (!Q && P) && ((!R || Q) || P))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool conclusion(bool P, bool Q, bool R)
{
	// Change here
	if(!Q && R)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//bool to char converter
char cc(bool value)
{
	if(value)
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
	int validTest = 0;
	cout << "Row	P	Q	R	Prem	Concl" << endl;
	int rowIndex = 0;
	
	//super ugly code, I will convert to loops to reduce excess code
	bool P = true,Q = true, R = true;
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}			
	
	P = true,Q = true, R = false;
	rowIndex = 1;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;	
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}					
	
	P = true,Q = false, R = true;
	rowIndex = 2;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}					
	
	P = true,Q = false, R = false;
	rowIndex = 3;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;	
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}				
	
	P = false,Q = true, R = true;
	rowIndex = 4;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;	
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}				
	
	P = false,Q = true, R = false;
	rowIndex = 5;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;	
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}				
	
	P = false,Q = false, R = true;
	rowIndex = 6;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;	
	if(premise(P,Q,R) && !conclusion(P,Q,R))
	{
		cout << " The argument is invalid in row " << rowIndex << endl;
	}
	else
	{
		validTest++;
	}		
	
	P = false,Q = false, R = false;			
	rowIndex = 7;	
	cout << rowIndex << "       " << cc(P) << "       " << cc(Q) << "       " << cc(R) << "        " << cc(premise(P,Q,R)) << "       " << cc(conclusion(P,Q,R)) << endl;
	
	if(validTest == 7)
	{
		cout << "The argument is valid" << endl;
	}
}
int main()
{
	cout << "Evan Miller \nLab 1" << endl;
	printer();
return 0;
}
