#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *next, *back;
};

class List {
  Node *start, *cur;
public:
  List() : start(NULL), cur(NULL) {}
  ~List() {
    while (start != NULL) {
      Node *node = start;
      start = start->next;
      delete node;
    }
  }
  void push_back(int val) {
    Node *node = new Node {val, NULL, NULL};
    if (start == NULL) {
      cur = start = node;
      return;
    }
    cur->next = node;
    node->back = cur;
    cur = node;
  }

  void push_front(int val) {
    Node *node = new Node {val, NULL, NULL};
    if (start == NULL) {
      cur = start = node;
      return;
    }
    node->next = start;
    start->back = node;
    start = node;
  }
  void print() {
    Node *node = start;
    while (node != NULL) {
      printf("%d ", node->val);
      node = node->next;
    }
  }
  void pop_back() {
    if (start == NULL)
      return;
    Node *node = cur->back;
    delete cur;
    cur = node;
    if (cur != NULL)
      cur->next = NULL;
  }
};

int main() {
  List list;
  for (int i = 0; i < 10; ++i)
    list.push_back(i);
  for (int i = 20; i < 30; ++i)
    list.push_front(i);
  list.print();
  puts("");
  list.pop_back();
  list.print();
  puts("");
  return 0;
}
