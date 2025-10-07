/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    Write a program to compute the value of the expression:
      (A^N + B^M) mod K,
    where “mod” denotes the remainder of division.

  Input Format:
    Your program receives five integers: A, B, N, M, and K.

  Constraints:
    1<=A<=1000
    1<=B<=1000
    1<=K<=1000
    1<=N<=10^9
    1<=M<=10^9

  Output Format:
    Output a single number — the value of the expression.
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
  long long m, n;
  long long a, b, k;
  cin >> a >> b >> n >> m >> k;
  
  long long an = modpow(a, n, k)%k;
  long long bm = modpow(b, m, k)%k;
  long long res = ((an%k)+(bm%k)) % k;

  cout << res << endl;  
  return 0;
}
