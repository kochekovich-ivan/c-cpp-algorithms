/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Let A and B be two integers. 
    The least common multiple (LCM) of A and B is the smallest positive integer 
    that is divisible by both A and B without a remainder.

    Write a program that finds the least common multiple (LCM) of two given integers.

  Input Format:
    A single line contains two integers A and B.

  Constraints:
    -10^9 ≤ A ≤ 10^9
    -10^9 ≤ B ≤ 10^9

  Output Format:
    Output one integer — the least common multiple of A and B.
*/
#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
  while (b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return abs(a);
}

long long lcd(long long a, long long b) { 
  return abs(a*b)/gcd(a,b);
}


int main() {
  long long a;
  long long b;
  cin >> a >> b;

  cout << lcd(a, b) << endl;
  return 0;
}

