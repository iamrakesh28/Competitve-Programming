#include <iostream>
#include <vector>

using namespace std;


vector <string> rr, yy, bb;

pair <int, int> solve(int& a, int b, int n) {
  int first, second;
  if (a < b)
    first = -1;
  else if (a == b) {
    if (n == a + b) {
      
      return {0, b};
    }
    first = -1;
  }
  else {
    int temp = a - b - 1;
    temp = min(temp, b);
    first = temp;
    a = a - 2 * temp;
    if (b > temp) {
      a = a - (b - temp + 1);
      second = 2 * (b - temp) + 1;
    }
    else
      second = 0;
  }
  return {first, second};
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < q; ++i) {
    int n, r, o, y, g, b, v, poss = 1, temp;
    scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);
    rr.clear();
    yy.clear();
    bb.clear();
    pair <int, int> R, Y, B;
    // R green
    R = solve(r, g, n);
    if (R.first == -1)
      poss = -1;
    Y = solve(y, v, n);
    if (Y.first == -1)
      poss = -1;
    B = solve(b, o, n);
    if (B.first == -1)
      poss = -1;
    r = rr.size(), y = yy.size(), b = bb.size();
    if (n & 1) {
    }
    else {
      int 
    }
  }
  return 0;
}