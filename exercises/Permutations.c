/*
  Time limit: 0.5 seconds
  Memory limit: 64 megabytes

  Task:
    In combinatorics, a permutation of order n is any ordered sequence
    containing all integers from 1 to n exactly once.
    The total number of permutations of order n is n! (n factorial).

    For example, the six permutations of order 3 are:
      {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
      {2, 3, 1}, {3, 1, 2}, {3, 2, 1}.

    Two permutations σ and τ of length n can be compared lexicographically.
    Permutation σ is lexicographically smaller than τ if there exists
    a position k (1 ≤ k < n) such that:
      σ(i) = τ(i) for all i < k, and σ(k) < τ(k).

    Write a program to generate all permutations of length n
    in lexicographic order.

  Input Format:
    The input contains one integer n.

  Constraints:
    1 ≤ n ≤ 10

  Output Format:
    Output all permutations of length n.
    Print each permutation on a separate line.
*/
#include <stdio.h>
#include <stdlib.h>

int next_permutation(int *a, int n) {
  int i = n - 2;
  while (i >= 0 && a[i] >= a[i + 1]) i--;
  if (i < 0) return 0; 

  int j = n - 1;
  while (a[j] <= a[i]) j--;

  int tmp = a[i]; a[i] = a[j]; a[j] = tmp;

  for (int l = i + 1, r = n - 1; l < r; l++, r--) {
    tmp = a[l]; a[l] = a[r]; a[r] = tmp;
  }

  return 1; 
}

int main(void) {
  int n;
  scanf("%d",&n);
  int* arr = malloc(n*sizeof(int));
  for(int i = 0; i<n; i++) {
    arr[i] = i+1;
  } 

  do {
    for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
    printf("\n");
  } while (next_permutation(arr, n));
  return 0;
}
