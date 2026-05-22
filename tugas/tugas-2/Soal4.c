/*
 Source: Kalicharan, Advanced Topics in C, p.101 no.7
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
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

Node* toBinary(int n) {
  Node *head, *tail;
  head = tail = NULL;
  while(n) {
    int bit = n % 2;
    n /= 2;
    Node *temp = createNode(bit);
    if(head == NULL) {
      head = tail = temp;
      continue;
    }
    tail->next = temp;
    tail = temp;
  }
  return head;
}

int main() {
  int n;
  printf("Enter the number: ");
  scanf("%d", &n);
  Node *head = toBinary(n);
  while(head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }
  free(head);
  return 0;
}
