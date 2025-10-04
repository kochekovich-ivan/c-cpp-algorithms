/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes 
  
  Exercise:
    You are given an integer k. Write a program to compute the value of the function:  
      f(k) = (1^k + 2^k + 3^k + 4^k) mod 5,
    where “mod” denotes the remainder of division.

  Input format:
    Your program receives one integer k as input. Pay attention to the constraints!

  Constraints:
    0 <= k <= 10^100000

  Output format:
    Output a single number — the value of f(k).
*/
#include <iostream>
using namespace std;


int main() {
  string k;
  cin >> k; 

  int rem = 0; 
  for (char c : k) {
      rem = (rem * 10 + (c - '0')) % 4;
  }

  int result = (rem == 0) ? 4 : 0;
  cout << result << endl;  
  return 0;
}
