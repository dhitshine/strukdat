/*
 Source: Kalicharan, Advanced Topics in C, p.26 no. 12
 */

#include <stdio.h>

void getfreq(char *word, int freq[26]) {
  for(int i = 0; i < 26; i++){
    freq[i] = 0;
  }
  for(int i = 0; i < word[i]; i++) {
    char c = word[i];
    if(c >= 'a' && c <= 'z') {
      freq[c - 'a']++;
    }else if(c >= 'A' && c <= 'Z') {
      freq[c - 'A']++;
    }
  }
}

int comp(int A[26], int B[26]) {
  for(int i = 0; i < 26; i++) {
    if(A[i] != B[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  char words[100][100];
  int freq[100][26];
  int visited[100];
  printf("Enter number of words: ");
  scanf("%d", &n);
  printf("Enter the words:\n");
  for(int i = 0; i < n; i++){
    scanf("%s", words[i]);
    getfreq(words[i], freq[i]);
  }
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      int found = 0;
      for(int j = i + 1; j < n; j++) {
        if(!visited[j] && comp(freq[i], freq[j])) {
          if(!found) {
            printf("%s ", words[i]);
            found = 1;
          }
          printf("%s ", words[j]);
          visited[j] = 1;
        }
      }
      if(found) {
        printf("\n");
      }
    }
  }
}
