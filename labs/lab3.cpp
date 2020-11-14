#include <gmp.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char num1[40];
	char num2[40];
	
	cout << "\nEvan Miller \nCS250 \nLab 3" << endl;

	// get num
	cout << "\nInput your first big number, please: ";
	cin >> num1;
	cout << "\nInput your second big number, please: ";
	cin >> num2;
	cout << endl;

	//declare and init big nums
	mpz_t n1, n2, q, r;
	mpz_init(n1);
	mpz_init(n2);
	mpz_init(q);
	mpz_init(r);

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

//------------------------------
//Using mpz function to test
	cout << "GCD using built-in function: ";
	mpz_t ans;
	mpz_init(ans);
	mpz_gcd(ans, n1, n2);
	mpz_out_str(stdout, 10, ans);
	cout << endl;
//------------------------------

	cout << "\nGCD Using Euclidean Algorithm: " << endl;
	mpz_t dividen, divisor, gcdResult;
	mpz_init(dividen);
	mpz_init(divisor);
	mpz_init(gcdResult);

	if(n1 > n2)
	{
		mpz_set(divisor, n2);
		mpz_set(dividen, n1);
	}
	else
	{
		mpz_set(divisor, n1);
		mpz_set(dividen, n2);
	}
	mpz_fdiv_q(q, dividen, divisor);
	mpz_mod(r, dividen, divisor);
	mpz_set(gcdResult,divisor);
	while(r > 0)
	{
		mpz_set(dividen,divisor);
		mpz_set(divisor,r);
		mpz_fdiv_q(q, dividen, divisor);
		mpz_mod(r, dividen, divisor);
		if(r == 0)
		{
			mpz_set(gcdResult,divisor);
		}
	}
	mpz_out_str(stdout, 10, gcdResult);
	
	//clear big nums
	mpz_clear(n1);
	mpz_clear(n2);
	mpz_clear(q);
	mpz_clear(r);
	mpz_clear(ans);
	mpz_clear(dividen);
	mpz_clear(divisor);
	mpz_clear(gcdResult);
	
	return 0;
}

