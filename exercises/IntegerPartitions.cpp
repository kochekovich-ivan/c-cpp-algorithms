/*
  Time limit: 0.5 seconds
  Memory limit: 64 megabytes

  Exercise:
    A partition of an integer n is a representation of n as a sum of positive integers, 
    called parts. The order of parts does not matter, 
    that is, partitions that differ only by the order of parts are considered the same.

    Write a program to generate all partitions of the positive integer n.

  Input Format:
    The input data contains a single integer n.

  Constraints:
    1 ≤ n ≤ 16

  Output Format:
    Output all generated partitions in lexicographical order. 
    The parts in each partition must be sorted in non-decreasing order. 
    Print each partition on a separate line.
*/
#include <bits/stdc++.h>

using namespace std;

void PV(vector<long long>& cur) {
  for(auto x : cur) {
    cout << x << " ";
  }
  cout << "\n";
}

void GP(long long n, vector<long long>& cur, long long start) {
  if(n==0) { 
    PV(cur);
    return;
  }

  for (int i = 1; i<=n && i<=start; i++) {
    cur.push_back(i);
    GP(n-i, cur, i);
    cur.pop_back();
  }
}

int main() {
  long long n;
  cin >> n;
  vector<long long> cur;
  GP(n, cur, n); 

  return 0;
}
