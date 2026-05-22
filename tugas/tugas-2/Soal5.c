/*
 Source: Kalicharan, Advanced Topics in C, p.101 no.9
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

int toDecimal(Node *head) {
  int res = 0;
  int base = 1;
  Node *curr = head;
  while(curr != NULL) {
    res += curr->val * base;
    base *= 2;
    curr = curr->next;
  }
  return res;
}

Node* add1(Node *b1, Node *b2) {
  int sum = toDecimal(b1) + toDecimal(b2);
  return toBinary(sum);
}

Node* add2(Node *b1, Node *b2) {
  Node *head, *tail;
  head = tail = NULL;
  int carry = 0;
  while(b1 != NULL || b2 != NULL || carry > 0) {
    int sum = carry;
    if(b1 != NULL) {
      sum += b1->val;
      b1 = b1->next;
    }
    if(b2 != NULL) {
      sum += b2->val;
      b2 = b2->next;
    }
    int bit = sum % 2;
    carry = sum / 2;
    Node *temp = createNode(bit);

    if(head == NULL) {
      head = tail = temp;
    }else {
      tail->next = temp;
      tail = temp;
    }
  }
  return head;
}

int main() {
  int a = 13, b = 6;
  Node *head = add1(toBinary(a), toBinary(b));
  while(head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }
  head = add2(toBinary(a), toBinary(b));
  while(head != NULL) {
    printf("%d ", head->val);
    head = head->next;
  }
}
