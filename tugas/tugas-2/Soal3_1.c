/*
 Source: Kalicharan, Advanced Topics in C, p.26 no.12
 */

#include <stdio.h>
#include <string.h>

int anagram(char *A, char *B) {
  int freq[128] = {0};
  int lenA = strlen(A), lenB = strlen(B);
  if(lenA != lenB) {
    return 0;
  }
  for(int i = 0; i < lenA; i++) {
    freq[A[i]]++;
    freq[B[i]]--;
  }
  for(int i = 0; i < 128; i++) {
    if(freq[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char A[100], B[100];
  printf("Enter first word: ");
  scanf("%s", A);
  printf("Enter second word: ");
  scanf("%s", B);
  if(anagram(A, B)) {
    printf("Anagrams");
  }else {
    printf("Not Anagrams");
  }
  return 0;
}
