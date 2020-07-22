#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
};

class List {
  Node *start, *end;
  Node *part(int val, Node *node) {
    if (node == NULL)
      return NULL;
    if (val <= node->val)
      node->next =  part(val, node->next);
    else {
      Node *temp = node->next;
      node->next = start;
      start = node;
      return part(val, temp);
    }
    return node;
  }
  
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

  void partition(int val) {
    if (start == NULL)
      return;
    Node *temp = part(val, start->next);
  }
  
  void print() {
    Node *temp = start;
    while (temp != NULL) {
      printf("%d ", temp->val);
      temp = temp->next;
    }
    puts("");
  }

  /*
  ofstream& <<() const {
  }
  */
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
  int a[] = {3, 5, 8, 5, 10, 2, 1};
  for (int i = 0; i < 7; ++i)
    list.push_back(a[i]);
  list.print();
  list.partition(5);
  list.print();
  return 0;
}
