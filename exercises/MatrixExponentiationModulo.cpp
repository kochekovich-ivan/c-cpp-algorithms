/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Let A be a square matrix of size n × n:
        A = [a_ij]

    Write a program that computes the matrix A raised to the power k modulo M:
        A^k mod M

    where "mod" means the remainder after division.

  Input Format:
    The first line contains the integer n (1 ≤ n ≤ 20) — the size of the matrix A.
    The next n lines contain n integers each — the elements of matrix A.
    The last line contains two integers: k and M.

  Constraints:
    1 ≤ n ≤ 20
    1 ≤ a_ij ≤ 10^6
    1 ≤ k ≤ 10^18
    1 ≤ M ≤ 10^6

  Output Format:
    Output the resulting n × n matrix equal to:
        A^k mod M
*/
#include <iostream>
#include <vector>
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  Matrix A(n, vector<int64>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }

  int64 k, m;
  cin >> k >> m;

  Matrix result = matrix_pow(A, k, m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}

