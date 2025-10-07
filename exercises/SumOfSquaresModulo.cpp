/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    You are given an integer n. Write a program to compute the value of the function:
      f(n) = (1^2 + 2^2 + 3^2 + ... + n^2) mod (10^9 + 7)
    where mod means taking the remainder after division.

  Input Format:
    Your program will receive a single integer n.

  Constraints:
    1 <= n <= 10^9

  Output Format:
    Print a single number — the value of f(n).

*/
#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
  long long n;
  cin >> n;
  
  long long a = n % MOD;
  long long b = (n + 1) % MOD;
  long long c = (2 * n + 1) % MOD;

  long long res = (a*b) % MOD;
  res = (res * c) % MOD;

  res = (res * 166666668) % MOD;

  cout << res << endl;
  return 0;
}
