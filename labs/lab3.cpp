#include <gmp.h>
#include <iostream>
#include <string>

using namespace std;

mpz_t gcd(mpz_t, mpz_t);

int main()
{
	char num1[40];
	char num2[40];
	
	cout << "Evan Miller \nCS250 \nLab 3" << endl;

	// get num
	cout << "Input your first big number, please: ";
	cin >> num1;
	cout << "\nInput your second big number, please: ";
	cin >> num2;
	cout << endl;

	//declare and init big nums
	mpz_t n1, n2, q, r, gcd();
	mpz_init(n1);
	mpz_init(n2);
	mpz_init(q);
	mpz_init(r);
	mpz_init(gcd());

	//assign values from strings
	mpz_set_str(n1,num1,10);
	cout << "Big number 1 is: ";
	mpz_out_str(stdout,10,n1);
	mpz_set_str(n2,num2,10);
	cout << "\nBig number 2 is: ";
	mpz_out_str(stdout,10,n2);
	mpz_set_ui(q,0);
	mpz_set(r,n1);

	//compute
	while(mpz_cmp(r,n2)>= 0)
	{
		mpz_sub(r,r,n2);
		mpz_add_ui(q,q,1);
	}
	
	//output
	cout << "\nQuotient: ";
	mpz_out_str(stdout,10,q);
	cout << "\nRemainder: ";
	mpz_out_str(stdout,10,r);
	cout << endl;
	cout << "GCD: ";
	mpz_out_str(stdout, 10, gcd(*n1,*n2));
	cout << endl;

	//clear big nums
	mpz_clear(n1);
	mpz_clear(n2);
	mpz_clear(q);
	mpz_clear(r);

	return 0;
}
mpz_t gcd(mpz_t a,mpz_t b)
{
	if(b == 0)
	{
		return *a;
	}
	return gcd(b, mpz_mod(mpz_t r, *a, *b);
}
