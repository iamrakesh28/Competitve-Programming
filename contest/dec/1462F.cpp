#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
  int x, end, index;
  Point(int _x, int _end, int _index) : x(_x), end(_end), index(_index) {}
  bool operator< (const Point &pt) {
    if (this -> x != pt.x)
      return this -> x < pt.x;
    return this -> end < pt.end;
  }
};

vector <Point> points;
vector <int> _count;

int solveK(int n) {
  int cur = 0, good = 1, index = 0;
  queue <int> segs;
  for (int i = 0; i < n; ++i) {
    if (points[i].end < 0) {
      _map[points[i].i] = index;
      inv[index] = points[i].i;
      segs.push(index);

      int front = segs.front();
      prefsum[front]++;
      cur++;
      index++;
    }
    else {
      int front = segs.front();
      prefsum[front]++;
      cur--;
    }
    good = max(good, cur);
    // cout << cur << endl;
  }
  // cout << good << endl;
  n = n >> 1;
  return n - good;
}


int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);
    points.clear();
    _count.resize(n, 0);

    
    for (int i = 0; i < n; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      points.push_back(Point(r, 1, i));
      points.push_back(Point(l, -1, i));
      
    }

    sort(points.begin(), points.end());

    int k = 1;//solveK(n << 1);

    printf("%d\n", k);
  }
  return 0;
}
