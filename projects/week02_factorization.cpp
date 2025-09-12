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
	for (auto x : FF)
	{
		cout << x.Prime << "^" << x.Power << endl;
	}
	return 0;
}
