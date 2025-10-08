/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Given an integer N, determine the number of binary sequences (consisting of 0s and 1s)
    of length N that do not contain three consecutive ones.

  Input Format:
    The input contains one integer N.

  Constraints:
    1 ≤ N ≤ 35

  Output Format:
    Output one integer — the number of binary sequences of length N
    that do not contain three consecutive ones.
*/
#include <iostream>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  
  long long f1 = 2;
  long long f2 = 4;
  long long f3 = 7;
  long long fn;
 
  if(n==1) {
    cout << f1 << '\n';
  }  
  else if(n==2) {
    cout << f2 << '\n'; 
  }
  else if(n==3) {
    cout << f3 << '\n';
  }
  else {
    for(int i = 4; i<=n; i++) {
      fn = f1+f2+f3;
      f1=f2;
      f2=f3;
      f3=fn;
    } 
    cout << fn << '\n';
  }
  return 0;
}
