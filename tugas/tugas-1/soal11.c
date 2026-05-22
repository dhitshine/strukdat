/*
 Source: Kalicharan, Advanced Topics in C, p.26 no.11
 */

#include <stdio.h>

int main() {
  int A[] = {17, 24, 31, 39, 44, 49, 36, 29, 20, 18, 13};
  int n = sizeof(A) / sizeof(A[0]);
  int B[n];
  int peak = 0;
  for(int i = 1; i < n; i++) {
    if(A[i] < A[i - 1]) {
      peak = i - 1;
      break;
    }
  }
  int i = 0, j = n - 1, k = 0;
  while(i <= peak && j >= peak + 1) {
    if(A[i] < A[j]) {
      B[k] = A[i];
      k++, i++;
    }else {
      B[k] = A[j];
      k++, j--;
    }
  }
  while(i <= peak) {
    B[k] = A[i];
    k++, i++;
  }
  while(j >= peak + 1) {
    B[k] = A[j];
    k++, j--;
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", B[i]);
  }
  return 0;
}
