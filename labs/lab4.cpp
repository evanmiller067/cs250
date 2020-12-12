/*
NAME: Evan Miller
ASSIGNMENT: Lab 4
SOURCES: geeksforgeeks.org
*/

#include <iostream>

using namespace std;

void tower(int, char, char, char);

int main()
{
	int n;

	cout << "Evan Miler \nCS250 \n11/19/20 \nTower of Hanoi" << endl;
	cout << "Enter how many disks: " << flush;
	cin >> n;
	printf("Tower with %i disks and three poles \n", n);
	cout << "\nRECURSION: " << endl;

	tower(n, '1', '3', '2');

	return 0;
}
void tower(int n, char first, char third, char second)
{
	// n number of disks, three poles

	//base case
	if(n == 0)
	{
		return;
	}
	tower(n-1, first, second, third);
	printf("Moved disk from %c to %c\n", first, third);
	
	tower(n-1, second, third, first);
}
