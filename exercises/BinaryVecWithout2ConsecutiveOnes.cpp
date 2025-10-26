/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    Write a program to generate all binary vectors of length n 
    that do not contain two consecutive ones.

  Input Format:
    The input data contains a single integer n.

  Constraints:
    1 ≤ n ≤ 16

  Output Format:
    In the first line, print the number of binary vectors of length n 
    that do not contain two consecutive ones.
    In the following lines, print the generated vectors in lexicographical order.
*/
#include <iostream>
using namespace std;

int n; 

long long count_no_adjacent_ones(int len, char last)
{
  if (len == n) return 1;

  long long cnt = 0;

  cnt += count_no_adjacent_ones(len + 1, '0');

  if (last != '1')
    cnt += count_no_adjacent_ones(len + 1, '1');

  return cnt;
}

void create_vec(string s)
{
  if (s.size() == n)
  {
    cout << s << endl;
    return;
  }

  create_vec(s + '0');

  if (s.empty() || s.back() != '1')
    create_vec(s + '1');
}

int main()
{
  cin >> n;
  long long total = count_no_adjacent_ones(0, '0');
  cout << total << endl;
  create_vec("");
  return 0;
}
