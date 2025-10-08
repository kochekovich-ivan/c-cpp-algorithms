/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Write a program to compute the value of the expression:
        A * B mod M
    where "mod" means the remainder after division.

  Input Format:
    The input consists of a single line containing three positive integers:
        A, B, and M.

  Constraints:
    1 ≤ A ≤ 10^18
    1 ≤ B ≤ 10^18
    1 ≤ M ≤ 10^18

  Output Format:
    Output one number — the value of the expression:
        (A * B) mod M
*/
#include<iostream>

using namespace std;

long long mulmod(long long a, long long b, long long mod) {
  return (long long)((__int128)a * b % mod);
}

int main() {
  long long a, b ,m;
  cin >> a >> b >> m;
  long long res = mulmod(a, b, m);
  cout << res << endl;
  return 0;
}
