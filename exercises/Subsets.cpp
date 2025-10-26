/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    Let M = {1, 2, …, n} be a set with n elements. 
    Write a program that generates all non-empty subsets of the set M.

  Input Format:
    The input data contains a single integer n.

  Constraints:
    1 ≤ n ≤ 10

  Output Format:
    Output all generated subsets of the set M. 
    Each line should contain one subset: 
    the first number in the line — the number of elements in the subset, 
    followed by the elements of the subset.
*/
#include <bits/stdc++.h>
using namespace std;

void PV(vector<long long>& vec) {
  vector<long long> FF;
  int n = vec.size();
  int i = n-1;
  while(i>=0) {
    if(vec[i] == 1) {
      FF.push_back(n-i);
    }
    i--;
  }
  cout << FF.size() << " ";
  for(auto x : FF) {
    cout << x << " ";
  }
  cout << "\n";
}

vector<long long> NBV(vector<long long> vec) {
  int n = vec.size();
  int i = n - 1;
  while(i >= 0 && vec[i] != 0) {
    vec[i] = 0;
    i--;
  } 
  if (i<0)
    return vec;
  vec[i] = 1;
  return vec;
}

int main() {
  long long n;
  cin >> n;
  vector<long long> vec(n, 0);

  for(int i = 0; i<pow(2,n)-1; i++) {
    vec = NBV(vec);
    PV(vec);
  }

  return 0;
}
