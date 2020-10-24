#include <iostream>
#include <vector>

using namespace std;
const int inf = 1e9;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

class MinHeap {
private:
  vector <int> arr;
  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }

  void MinHeapify(int i) {
    int size = arr.size();
    int l = left(i);
    int r = right(i);
    int small = i;
    if (l < size && arr[l] < arr[i])
      small = l;
    if (r < size && arr[r] < arr[small])
      small = r;
    if (small != i) {
      swap(arr + small, arr + i);
      MinHeapify(small);
    }
    return;
  }
  
public:

  void insert(int x) {
    int size = arr.size(), par;
    arr.push_back(x);
    // travel up
    par = parent(size);
    while (size && arr[par] > arr[size]) {
      size = par;
      swap(arr + par, arr + size);
      par = parent(size);
    }
    return;
  }

  int Min() {
    if (arr.size())
      return arr[0];
    return inf;
  }
  int extractMin() {
    if (arr.size() <= 0)
      return inf;
    if (arr.size() == 1) {
      int minVal = arr[0];
      arr.pop_back();
      return minVal;
    }
    
  }
};

int main() {
  return 0;
}
