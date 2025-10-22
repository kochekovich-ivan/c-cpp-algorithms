/*
  Time limit: 0.2 seconds
  Memory limit: 64 megabytes

  Task:
    Let M be a set of n distinct elements.
    A combination (or subset) of n choose k
    is a way to select k elements from the given set M,
    where the order of elements does not matter.

    Write a program to generate all combinations of n choose k.

  Input Format:
    The input contains two integers n and k.

  Constraints:
    1 ≤ k ≤ n ≤ 16

  Output Format:
    Output all generated combinations in lexicographic order.
    Print each combination on a separate line.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  int *arr = malloc(k * sizeof(int));
  for (int i = 0; i < k; i++) arr[i] = i + 1;

  while (1) {
    for (int i = 0; i < k; i++)
      printf("%d ", arr[i]);
    printf("\n");

    int i = k - 1;
    while (i >= 0 && arr[i] == n - k + i + 1) i--;
    if (i < 0) break;

    arr[i]++;
    for (int j = i + 1; j < k; j++)
      arr[j] = arr[j - 1] + 1;
  }

  free(arr);
  arr = NULL;
  return 0;
}

