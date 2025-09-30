/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Exercise:
    Carl Friedrich Gauss (1777–1855) is one of the greatest mathematicians of all time.
    There’s a famous story about how, while at school, he surprised his teacher by quickly summing all the numbers from 1 to 100. 
    He simply grouped them into 50 pairs: 1+100, 2+99, and so on, getting the result 5050.

    Let’s look at adding consecutive numbers in more detail. 
    For example, starting from 13 you can make the following consecutive sums:
      13 + 14 + 15 = 42.
    On the other hand, 42 can also be obtained by adding other consecutive numbers from the natural series:
      3 + 4 + 5 + 6 + 7 + 8 + 9 = 42.

    You are given a number k.
    Find all segments of consecutive natural numbers whose sum equals k 
    (note that only segments with length of at least 2 should be considered).
    Output the intervals sorted by their left endpoint in the format [a, b] (a space between a and b).

  Input Format:
    Your program receives one integer k.
 
  Constraints:
    1 <= k <= 10^11

  Output Format:
    Output the number of intervals and the intervals themselves.
    See the examples in the problem statement for clarification.
    If no such intervals exist, simply output 0.
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void G(long k) {
  vector<pair<long, long>> FF;
  for(long l = 1; l * l < 2 * k; l++) {
    if( (k - l * (l + 1) / 2) % (l + 1) == 0 ) {
      long a = (k - l * (l + 1) / 2) / (l + 1);
      long b = a + l;
      if(a > 0)
        FF.push_back({a, b}); 
    }    
  }
  cout << FF.size() << endl;
  for(auto it = FF.rbegin(); it != FF.rend(); it++) {
    cout << "[" << it->first << ", " << it->second << "]" << endl;
  }
}


int main() {
  long k;
  cin >> k;
  G(k);
  return 0;
}

