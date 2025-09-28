/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    The fundamental theorem of arithmetic states that every natural number greater than one can be represented uniquely (up to the order of factors) as a product of prime numbers.
    Representing a natural number as a product of primes is called its prime factorization. Write a program that finds the prime factorization of a given natural number.

  Input Format:
    The input data contains a single integer N.

  Constraints:
    2<=N<2^31-1

  Output Format:
    Print the number N as a product of powers of prime numbers in the form:
      N = p₁^a₁ * p₂^a₂ * ... * pk^ak
    The factors in the product must be listed in ascending order of the prime numbers.
    If there is more than one factor, they must be separated by the symbol *.
    There should be one space before and after each *.  
*/
#include <iostream>
#include <vector>

using namespace std;

struct Factor
{
	long long Prime;
	long long Power;
};

vector<Factor> Factorisation(long long n)
{
	Factor F;
	vector<Factor> FF;
	long long d{ 2 };
	while (n != 1)
	{
		if (n % d == 0)
		{
			F.Power = 0;
			F.Prime = d;
			while (n % d == 0)
			{
				n /= d;
				F.Power += 1;
			}
			FF.push_back(F);
		}
		d++;
		if (n != 1 && d * d > n)
		{
			FF.push_back({ n, 1 });
			break;
		}
	}

	return FF;

}


int main()
{
	long long n;
	cin >> n;
	vector<Factor> FF = Factorisation(n);
    cout << n << " = "; 
	for (size_t i = 0; i < FF.size(); i++)
	{
		cout << FF[i].Prime << "^" << FF[i].Power;
		if (i != FF.size() - 1) 
			cout << " * ";
	}
	cout << endl;
	return 0;
}
