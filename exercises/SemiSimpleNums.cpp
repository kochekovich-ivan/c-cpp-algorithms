/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes
  
  Exercise:
    A semiprime number (or biprime number) is a positive integer that is the product of two prime numbers.
    The sequence of semiprime numbers begins as follows:
      4, 6, 9, 10, 14, 15, 21, 22, 25, 26, 33, 34, 35, 38, 39, 46, 49, 51, 55, 57, 58, 62, 65, 69, 74, …
    You are given an integer k. Write a program that finds the semiprime number at position k.

  Input Format:
    Your program receives a single integer k.

  Constraints:
    1<=k<=1000

  Output Format:
    Print the k-th semiprime number.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    int d = 2;
    if (n < d)
        return false;
    if (n == 2)
        return true;
    for (; n % d != 0 && d * 1LL * d <= n; d++)
    {
    }
    if (n % d == 0)
        return false;
    return true;
}

bool isSemiPrime(int n) {
  for(int d = 2; d*d*1LL <= n; d++) {
    if(n%d==0) {
      int q = n/d;
      if(isPrime(q) && isPrime(d))
        return true;
    }
  }
  return false;
}

vector<int> k_np(int k) {
  vector<int> result;
  int n = 4;
  while(int(result.size() < k)) {
    if(isSemiPrime(n)) 
      result.push_back(n);
      n++;
  }
  return result;
}

int main() {
  int k;
  cin >> k;
  vector<int> res = k_np(k);
  cout<<res[k-1]<<endl;
  return 0;
}

