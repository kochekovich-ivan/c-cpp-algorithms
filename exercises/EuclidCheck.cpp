/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    The well-known Euclidean algorithm is used to find the greatest common divisor (GCD):

    1. Let a and b be the numbers whose GCD we need to find.
    2. If b = 0, then the number a is the required GCD.
    3. If b > a, swap a and b.
    4. Replace a with a − b.
    5. Return to step 2.

    You need to determine whether, during the execution of the Euclidean Algorithm 
    for the given pair of numbers (a, b), there will be a moment before step 2 
    when the numbers are equal to (c, d).

  Input Format:
    The first line of input contains an integer K — the number of test cases to perform.
    Then K blocks follow. Each block consists of two lines:
      - The first line contains a pair of numbers (a, b).
      - The second line contains a pair of numbers (c, d).

  Constraints:
    1 ≤ K ≤ 100
    1 ≤ a ≤ 10¹⁸
    1 ≤ b ≤ 10¹⁸
    1 ≤ c ≤ 10¹⁸
    1 ≤ d ≤ 10¹⁸

  Output Format:
    For each test case, output "YES" if during the Euclidean algorithm for (a, b)
    there is a moment when the pair equals (c, d).
    Otherwise, output "NO".
*/
#include <iostream>

using namespace std;

bool check(long a, long b, long c, long d) {
  if(a == c && b == d) {
    return true;
  }
  while (b!=0) {
    if(d==b && c<a && c>= a%b && (c-a%b) %b == 0) return true;
    a = a%b;
    swap(a, b);
  }
  return false;
}

int main() {
  int K;
  long a, b, c, d;
  cin>>K;
  while(K--) {
    cin>>a>>b>>c>>d;
    if(check(a,b,c,d)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}
