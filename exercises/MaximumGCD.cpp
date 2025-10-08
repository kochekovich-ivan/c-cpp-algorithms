/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    You are given a positive integer N.

    Consider all pairs of positive integers (A, B) such that:
        A + B = N

    Write a program to find such a pair (A, B) for which the greatest common divisor (GCD)
    of A and B is as large as possible.

  Input Format:
    The input contains one integer N.

  Constraints:
    2 ≤ N ≤ 10^9

  Output Format:
    Output two positive integers A and B such that:
        A + B = N
    and the greatest common divisor (GCD) of A and B is maximal.
    If there are multiple valid pairs, output any of them.
*/
#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long best_gcd = 1;

  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long d1 = i;
      long long d2 = n / i;

      if (d1 <= n / 2 && d1 > best_gcd) best_gcd = d1;
      if (d2 <= n / 2 && d2 > best_gcd) best_gcd = d2;
    }
  }

  long long best_a = n - best_gcd;
  long long best_b = best_gcd;

  cout << best_a << " " << best_b << endl;
  return 0;
}
