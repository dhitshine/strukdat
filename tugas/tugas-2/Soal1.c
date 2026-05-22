/*
 Source: Kalicharan, Advanced Topics in C, p.26 no.10
 */

#include <stdio.h>

int main() {
  int A[] = {5, 11, 19, 28, 35, 42};
  int B[] = {50, 44, 31, 27, 18, 9};
  int nA = sizeof(A) / sizeof(A[0]);
  int nB = sizeof(B) / sizeof(B[0]);
  int nC = nA + nB;
  int C[nC];
  int i = 0, j = nB - 1, k = 0;

  while(i < nA && j >= 0) {
    if(A[i] < B[j]) {
      C[k++] = A[i++];
    }else {
      C[k++] = B[j--];
    }
  }
  while(i < nA) {
    C[k++] = A[i++];
  }
  while(j >= 0) {
    C[k++] = B[j--];
  }

  for(int i = 0; i < nC; i++) {
    printf("%d ", C[i]);
  }
  return 0;
}
