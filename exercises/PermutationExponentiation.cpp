/*
  Time limit: 0.3 seconds
  Memory limit: 64 megabytes

  Task:
    A permutation of order n is a bijective mapping of the set {1, 2, 3, ..., n} onto itself:

        θ : {1, 2, 3, ..., n} → {1, 2, 3, ..., n}

    It is convenient to represent a permutation θ of order n as a table with two rows and n columns:

        θ = ( 1   2   3   ...   n )
            ( θ(1) θ(2) θ(3) ... θ(n) )

    where each θ(i) is an integer from 1 to n.
    The total number of permutations of order n equals n!.

  Composition of permutations:
    Let σ and τ be two permutations of order n:

        σ = ( 1   2   3   ...   n )
            ( σ(1) σ(2) σ(3) ... σ(n) )

        τ = ( 1   2   3   ...   n )
            ( τ(1) τ(2) τ(3) ... τ(n) )

    Their composition (σ ○ τ) is defined as:

        (σ ○ τ)(i) = σ(τ(i))

    Example:
        σ = ( 1  2  3  4 )
            ( 2  1  4  3 )

        τ = ( 1  2  3  4 )
            ( 3  4  1  2 )

        Then (σ ○ τ) = ( 1  2  3  4 )
                        ( 4  3  2  1 )

  Write a program that, given a permutation θ of order n, computes the permutation θ^k
  (the composition of θ with itself k times).

  Input Format:
    The first line contains two integers n and k.
    The second line contains n distinct integers θ(1), θ(2), ..., θ(n) describing the permutation θ.

  Constraints:
    1 ≤ n ≤ 10^5
    1 ≤ k ≤ 10^18

  Output Format:
    Output n integers — the permutation corresponding to θ^k.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> compose(const vector<int>& a, const vector<int>& b) {
  int n = a.size();
  vector<int> res(n);
  for (int i = 0; i < n; i++)
    res[i] = a[b[i] - 1]; 
  return res;
}

vector<int> binpow(vector<int> perm, long long k) {
  int n = perm.size();
  vector<int> res(n);
  iota(res.begin(), res.end(), 1);
  while (k > 0) {
    if (k & 1) res = compose(res, perm);
    perm = compose(perm, perm);
    k >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  vector<int> ans = binpow(p, k);
  for (int x : ans) cout << x << " ";
  cout << "\n";
}

