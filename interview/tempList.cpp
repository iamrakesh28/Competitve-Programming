#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
};

class List {
  Node *start, *end;
public:
  List() : start(NULL), end(NULL) {}
  
  void push_back(int val) {
    Node *node = new Node {val, NULL};
    if (start == NULL) {
      start = end = node;
      return;
    }
    end->next = node;
    end = node;
  }
  
  void print() {
    Node *temp = start;
    while (temp != NULL) {
      printf("%d ", temp->val);
      temp = temp->next;
    }
    puts("");
  }
  ~List() {
    while (start != NULL) {
      Node *next = start->next;
      delete start;
      start = next;
    }
  }
};

int main() {
  List list;
  return 0;
}
