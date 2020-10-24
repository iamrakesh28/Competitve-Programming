#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
};

/*
struct List {
  Node *head, *head;
};
*/

Node* partition(Node *node, int x) {
  Node *head, *tail, *cur, *temp;
  if (node == NULL)
    return NULL;
  head = tail = node;
  cur = node -> next;
  while (cur != NULL) {
    temp = cur -> next;
    // insert at head
    if (cur -> data < x) {
      cur -> next = head;
      head = cur;
    }
    // insert at tail
    else {
      tail -> next = cur;
      tail = cur;
      tail -> next = NULL;
    }
    cur = temp;
  }
  return head;
}

void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node -> data);
    node = node -> next;
  }
  puts("");
  return ;
}

Node *create(int arr[], int n) {
  Node *head = NULL;
  for (int i = n - 1; i >= 0; --i) {
    Node *node = new Node;
    node -> data = arr[i];
    node -> next = head;
    head = node;
  }
  return head;
}
int main() {
  int arr[] = {3, 5, 8, 5, 10, 2, 1};
  Node *head = create(arr, 7);
  printList(head);
  head = partition(head, 5);
  printList(head);
  return 0;
}
