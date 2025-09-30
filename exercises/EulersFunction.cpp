/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    The Euler’s totient function φ(n) is a multiplicative arithmetic function equal to the number of positive integers less than 
    n that are coprime with it. By definition, the number 1 is coprime with all numbers, and φ(1)=1.

    For example, for the number 24, there are 8 numbers less than it that are coprime with it:
    (1,5,7,11,13,17,19,23), so φ(24)=8.

    The function is named after Euler, who first used it in 1760 in his work on number theory to prove Fermat’s Little Theorem, 
    and later to prove a more general statement – Euler’s theorem.

    In explicit form, Euler’s totient function is expressed by the formula:
    φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pr),
  
    where p1, p2, ..., pr are the distinct prime dibisors of n.

  Input format:
    The input data contains a single integer n.
 
  Constraints:
    1 <= n <= 2^31 - 1

  Output format:
    Output a single integer — φ(n).
*/
#include <iostream>
#include <vector>
using namespace std;

struct Factor {
  int Power;
  int Prime;
};

vector<Factor> Factorization(long long n) {
  Factor F;
  vector<Factor> FF;
  if(n%2==0) {
    int power = 0;
    while(n%2==0) {
      n/=2;
      power++;
    }
    FF.push_back({power, 2});
  }
  for(long long d = 3; d*d<=n; d+=2) {
    if(n%d==0) {
      int power = 0;
      while(n%d==0) {
        n/=d;
        power++;
      }
    FF.push_back({power, (int)d});
    }
  }
  if(n>1) {
    FF.push_back({1, (int)n});
  }
  return FF;
}

int E(int n) {
  if(n == 1)
    return 1;
  vector<Factor> FF = Factorization(n);
  long long ans = n;
  for(auto x : FF) 
    ans = ans * (x.Prime - 1) / x.Prime;
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << E(n) << endl; 
  return 0;  
}
