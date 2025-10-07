/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    You are given an integer n. Write a program to compute the value of the function:
      f(n) = (1^3 + 2^3 + 3^3 + 4^3 + ... + n^3) mod (10^9 + 7)
    where “mod” denotes the remainder of division.

  Input Format:
    Your program receives a single integer n.

  Constraints:
    1 <= n <= 10^9

  Output Format:
    Output a single number — the value of f(n).
*/
#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  long long sum = n % MOD * ((n + 1) % MOD) % MOD;
  long long half = (sum * 500000004) % MOD;
  long long res = (half * half) % MOD;
    

  cout << res << endl; 
  return 0;
}

