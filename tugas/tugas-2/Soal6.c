/*
 Source: Kalicharan, Advanced Topics in C, p.101 no.12
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next, *prev;
} Node;

Node* createNode(int val) {
  Node *node = (Node*) malloc(sizeof(Node));
  if(node == NULL) {
    return NULL;
  }
  node->val = val;
  node->next = NULL;
  return node;
}

Node* circular(int n) {
  Node *head, *temp, *tail;
  head = tail = NULL;
  for(int i = 1; i <= n; i++) {
    temp = createNode(i);
    if(head == NULL) {
      head = tail = temp;
    }else {
      tail->next = temp;
      tail->next->prev = tail;
      tail = temp;
    }
  }
  tail->next = head;
  head->prev = tail;
  return head;
}

int remaining(int n, int m) {
  Node *head = circular(n);
  Node *curr = head;
  while(curr->next != curr) {
    if(m > 0) {
      for(int i = 1; i < m; i++){
        curr = curr->next;
      }
    }else {
      for(int i = 1; i < -m; i++){
        curr = curr->prev;
      }
    }
    Node *del = curr;
    curr = curr->next;
    del->prev->next = del->next;
    del->next->prev = del->prev;
    free(del);
  }
  int ans = curr->val;
  free(curr);
  return ans;
}

int main() {
  int n, m;
  printf("Enter number of children: ");
  scanf("%d", &n);
  printf("Enter number of words: ");
  scanf("%d", &m);
  int win = remaining(n, m);
  printf("Last remaining: %d", win);
  return 0;
}
