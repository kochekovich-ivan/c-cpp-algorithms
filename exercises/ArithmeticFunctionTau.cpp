/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  The arithmetic function τ : N → N is defined as the number of positive integer divisors of a positive integer n:
    τ(n) = Σ_{d|n} 1
  The function τ is multiplicative, meaning that:
    gcd(m, n) = 1  ⇒  τ(m * n) = τ(m) * τ(n)
  If the number n can be factorized as:
     n = p1^s1 * p2^s2 * ... * pr^sr
  Then, by the multiplicativity property, τ(n) can be calculated as:
      τ(n) = τ(p1^s1) * τ(p2^s2) * ... * τ(pr^sr)
           = (s1 + 1) * (s2 + 1) * ... * (sr + 1)

  Input Format:
    The input data contains a single integer n.

  Constraints:
    1<n<=2^31-1

  Output Format:
    Print a single number — the count of positive divisors of n.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Factor {
  int Power;
  int Prime;
};

vector<Factor> Factorization(int n) {
  Factor F;
  vector<Factor> FF;
  int d = 2;
  while(n!=1) {
    if(n%d*1LL==0) {
      F.Power = 0;
      F.Prime = d;
      while(n%d*1LL==0) {
        n/=d;
        F.Power++;
      }
      FF.push_back(F);
    }
    d++;
    if(n!=1 && d*1LL*d > n) {
      FF.push_back({ 1, n});
      break;
    }
  }
  return FF;
}

int t(int n) {
  vector<Factor> FF = Factorization(n);
  int ans = 1;
  for(auto x : FF) 
    ans = ans * (x.Power + 1);
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << t(n) << endl; 
  return 0;  
}
