/*
Time limit: 0.2 seconds
Memory limit: 64 megabytes

Exercise:
  Write a program that finds the closest prime number to a given integer N. 
  In other words, you need to find the smallest prime number P such that the absolute difference ∣N−P∣ is minimized.

Input format:
  Your program receives a single integer N as input.

Constraints:
  1 <= N <= 2 * 10^9

Output format:
  Output the prime number closest to the given number N. 
  If there are two prime numbers equally close, output the smaller one.
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
  int d = 2;
  if (n < d) 
    return false;
  if(n == 2)
    return true;
  for(; n % d != 0 && d * 1LL * d <= n; d++) 
  {}
  if(n%d==0)
    return false;
  return true;
}

int main() {
  int n;
  cin >> n;
  if(isPrime(n)) {
    cout<<n<<endl;
    return 0;
  }
  int opn = n;
  while(opn > 1 && !isPrime(opn)) {
    opn--;
  }
  int res1 = (opn > 1 ? opn : -1); 
  opn = n;
  while(!isPrime(opn)) {
    opn++;
  }
  int res2 = opn;
  if(abs(n-res1) == abs(n-res2)) {
    cout<<res1<<endl;
    return 0;
  }
  if(abs(n-res1) < abs(n-res2)) {
    cout << res1 << endl;
    return 0;
  }
  cout<<res2<<endl;
  return 0;
}
