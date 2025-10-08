/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Write a program to compute the value of the expression:
        A^B mod M
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
        (A^B) mod M
*/
#include<iostream>

using namespace std;

long long modpow(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((__int128)res * a) % m;
      a = ((__int128)a * a) % m;
      b >>= 1;
    }
  return res;
}


int main() {
  long long a, b ,m;
  cin >> a >> b >> m;
  long long res = modpow(a, b, m);
  cout << res << endl;
  return 0;
}
