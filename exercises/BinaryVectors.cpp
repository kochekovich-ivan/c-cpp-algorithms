/*
  Time limit: 1 second
  Memory limit: 64 megabytes

  Task:
    A binary vector of length n is defined as a string of n symbols,
    each being either 0 or 1.
    For example, "10111" is a binary vector of length 5.

    Write a program to generate all binary vectors of length n
    in lexicographic order.

  Input Format:
    The input contains one integer n.

  Constraints:
    1 ≤ n ≤ 16

  Output Format:
    Output all binary vectors of length n in lexicographic order.
    Print each vector on a separate line.
*/
#include <iostream>

using namespace std;
int n;
void create_vec(string s)
{
  if(s.size() == n)
  {
    cout << s << endl;
    return;
  }
  create_vec(s + '0');
  create_vec(s + '1');

}
int main()
{
  cin >> n;
  string s;
  create_vec(s);
  return 0;
}
