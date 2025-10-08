/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Let A and B be two integers. Any number that divides both A and B
    is called their common divisor. The largest of such numbers is called
    the greatest common divisor (GCD).

    Every pair of integers has at least two common divisors: +1 and -1.
    If these are the only common divisors, such numbers are called coprime.

    Write a program that finds the greatest common divisor (GCD)
    of two given integers.

  Input Format:
    A single line contains two integers A and B.

  Constraints:
    -10^9 ≤ A ≤ 10^9
    -10^9 ≤ B ≤ 10^9

  Output Format:
    Output one integer — the greatest common divisor of A and B.

*/
#include <iostream>
using namespace std;

int main() {
  long long a;
  long long b;
  cin >> a >> b;

  a = a < 0 ? -a : a;
  b = b < 0 ? -b : b;

  while (b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  cout << a << endl;  
  return 0;
}

