/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Fibonacci numbers are the elements of the sequence:
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
    where each number is the sum of the two preceding ones.
    Formally, the Fibonacci sequence is defined as:

        F₀ = 0,
        F₁ = 1,
        Fₙ = Fₙ₋₁ + Fₙ₋₂.

    Fibonacci numbers grow very quickly, for example:
        F₅₀ = 12,586,269,025
        F₁₀₀ = 354,224,848,179,261,915,075

    Write a program that, given n, finds the remainder of division of Fₙ by 10⁹ + 7.

  Input Format:
    The input contains one integer n.

  Constraints:
    0 ≤ n ≤ 2 × 10⁹

  Output Format:
    Output one integer — the value of Fₙ modulo 10⁹ + 7.
*/
#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

using int64 = long long;
using Matrix = vector<vector<int64>>;


Matrix multiply(const Matrix &A, const Matrix &B, int64 m) {
  int n = A.size();
  Matrix C(n, vector<int64>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
      }
    }
  }
  return C;
}

Matrix matrix_pow(Matrix A, int64 k, int64 m) {
  int n = A.size();
  Matrix res(n, vector<int64>(n, 0));
  for (int i = 0; i < n; i++) res[i][i] = 1;
  while (k > 0) {
    if (k & 1) res = multiply(res, A, m);
    A = multiply(A, A, m);
    k >>= 1;
  }
  return res;
}

int main() {
  int64 n;
  cin >> n;
  if(n == 0) {
    cout << 0 << endl;
    return 0;
  } 
  else if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  Matrix M(2, vector<int64>(1, 0));
  Matrix S(2, vector<int64>(2, 1));
  S[1][1] = 0;
  M[0][0] = 1;
  S = matrix_pow(S, n-1, MOD);
  S = multiply(S, M, MOD);
  int64 res = S[0][0] % MOD;
  cout << res << endl;  
  return 0; 
}
