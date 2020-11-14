#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

// structure of big number
struct bigNum 
{
	char sign;
	char num[201];
}; 
typedef struct bigNum BIGNUM;

// for initialization
BIGNUM newVal() 
{
	BIGNUM x;
	x.sign = '+';
	for (int i = 0; i<201; i++)
	{
		x.num[i] = '\0';
	}
}
// return number of digits
int getSize(BIGNUM a) 
{
	int i = 0;
	while (a.num[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
// remove leading all zero from a numbers
BIGNUM removeLeadingZero(BIGNUM b)
{
	int n = getSize(b);
	int l = 0;
	for (int j = 0; j<n; j++) 
	{
		// number of leading zeros
		if (b.num[j] == '0') 
		{
			l++;
		}
		else 
		{
			break;
		}
	}
	// rewrite digits
	for (int j = l; j<n; j++) 
	{
		b.num[j - l] = b.num[j];
	}
	b.num[n - l] = '\0';
	return b;
}
// compare two digits
// for big or small
// or equal
int compare(BIGNUM a, BIGNUM b) 
{
	int n = getSize(a);
	int n1 = getSize(b);
	if (n1 != n) 
	{
		if (n1>n) 
		{
			return -1;
		}
		else 
		{
			return 1;
		}
	}
	else 
	{
		int x = 0;
		for (int i = 0; i<n; i++) 
		{
			if (a.num[i]>b.num[i]) 
			{
				x = 1;
				break;
			}
			else if (a.num[i]<b.num[i]) 
			{
				x = -1;
				break;
			}
		}
		return x;
	}
}
// reverse string
// to perform sum
BIGNUM reverse(BIGNUM a) 
{
	int n = getSize(a);
	for (int i = 0; i<n / 2; i++) 
	{
		char temp = a.num[i];
		a.num[i] = a.num[n - i - 1];
		a.num[n - i - 1] = temp;
	}
	return a;
}
// sum or subtraction
BIGNUM sum(BIGNUM a, BIGNUM b) 
{
	BIGNUM x = newVal();
	// if same sine
	// perform adition
	if (a.sign == b.sign) 
	{
		int n1 = getSize(a);
		int n2 = getSize(b);
		BIGNUM ba = reverse(a);
		BIGNUM bb = reverse(b);
		x.sign = a.sign;
		int carry = 0, i1 = 0, i2 = 0;
		int index = 0;
		while (i1<n1 || i2<n2) 
		{
			if (i1<n1 && i2<n2) 
			{
				int sum = (ba.num[i1] - '0') + (bb.num[i2] - '0') + carry;
				carry = sum / 10;
				sum = sum % 10;
				x.num[index] = (char)(sum + '0');
				index++;
				i1++;
				i2++;
			}
			else 
			{
				if (i1<n1) 
				{
					int sum = (ba.num[i1] - '0') + carry;
					carry = sum / 10;
					sum = sum % 10;
					x.num[index] = (char)(sum + '0');
					index++;
					i1++;
				}
				if (i2<n2) 
				{
					int sum = (bb.num[i2] - '0') + carry;
					carry = sum / 10;
					sum = sum % 10;
					x.num[index] = (char)(sum + '0');
					index++;
					i2++;
				}
			}
		}
		if (carry == 1) 
		{
			x.num[index] = '1';
			index++;
		}
		x.num[index] = '\0';
	}
	// opposite sign
	// perform subtraction
	else 
	{
		int comp = compare(a, b);
		if (comp != 0) 
		{
			// specify big and small number
			BIGNUM big, small;
			if (comp == -1) 
			{
				big = reverse(b);
				small = reverse(a);
				x.sign = b.sign;
			}
			if (comp == 1) 
			{
				big = reverse(a);
				small = reverse(b);
				x.sign = a.sign;
			}
			int n1 = getSize(big);
			int n2 = getSize(small);
			int carry = 0, i1 = 0, i2 = 0;
			int index = 0;
			while (i1<n1 || i2<n2) 
			{
				if (i1<n1 && i2<n2) 
				{
					int sum = (big.num[i1] - '0') - (small.num[i2] - '0') + carry;
					if (sum<0) 
					{
						sum = 10 + sum;
						carry = -1;
					}
					else 
					{
						carry = 0;
					}
					x.num[index] = (char)(sum + '0');
					index++;
					i1++;
					i2++;
				}
				else 
				{
					if (i1<n1) 
					{
						int sum = (big.num[i1] - '0') + carry;
						if (sum<0) {
							sum = 10 + sum;
							carry = -1;
						}
						else 
						{
							carry = 0;
						}
						x.num[index] = (char)(sum + '0');
						index++;
						i1++;
					}
					if (i2<n2) 
					{
						int sum = (small.num[i2] - '0') + carry;
						if (sum<0) {
							sum = 10 + sum;
							carry = -1;
						}
						else 
						{
							carry = 0;
						}
						x.num[index] = (char)(sum + '0');
						index++;
						i2++;
					}
				}
			}
			x.num[index] = '\0';
		}
		else 
		{
			x.num[0] = '\0';
			x.sign = '+';
		}
	}
	// reverse string after addition or subtraction
	x = reverse(x);
	x = removeLeadingZero(x);
	return x;
}
BIGNUM operator - (BIGNUM a, BIGNUM b) 
{
	b.sign = '-';
	BIGNUM x = sum(a, b);
	return x;
}
// if a > b
bool operator >(BIGNUM a, BIGNUM b) 
{
	int l1 = getSize(a);
	int l2 = getSize(b);
	if (l1>l2) 
	{
		return true;
	}
	else 
	{
		if (l1 == l2) 
		{
			for (int i = 0; i<l1; i++) 
			{
				if (a.num[i]>b.num[i]) 
				{
					return true;
				}
				if (a.num[i]<b.num[i]) 
				{
					return false;
				}
			}
		}
		else 
		{
			return false;
		}
	}
	return false;
}
BIGNUM gcd(BIGNUM a, BIGNUM b) 
{
	while (compare(a, b)) 
	{
		if (a>b) 
		{
			a = a - b;
		}
		else 
		{
			b = b - a;
		}
	}
	return a;
}
int main() 
{
	BIGNUM a = newVal(), b = newVal();
	char aa[200], bb[200];
	cout << "Enter first number : ";
	cin >> aa;
	cout << "Enter second number : ";
	cin >> bb;
	// assinging number in two big number
	int i = 0;
	if (aa[0] == '-') 
	{
		a.sign = '-';
		for (i = 1; i<strlen(aa); i++) 
		{
			a.num[i - 1] = aa[i];
		}
		a.num[i - 1] = '\0';
	}
	else 
	{
		a.sign = '+';
		for (i = 0; i<strlen(aa); i++) 
		{
			a.num[i] = aa[i];
		}
		a.num[i] = '\0';
	}
	i = 0;
	if (bb[0] == '-')
	{
		b.sign = '-';
		for (i = 1; i<strlen(bb); i++) 
		{
			b.num[i - 1] = bb[i];
		}
		b.num[i - 1] = '\0';
	}
	else 
	{
		b.sign = '+';
		for (i = 0; i<strlen(bb); i++) 
		{
			b.num[i] = bb[i];
		}
		b.num[i] = '\0';
	}
	// perform gcd of two numbers
	BIGNUM c = gcd(a, b);
	cout << "Greatest common devisor is : ";
	cout << c.sign;
	cout << c.num;
	return 0;
}
