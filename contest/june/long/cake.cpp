#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 5e3 + 5;

struct pt {
  ll x, y;
  pt() {}
  pt(ll _x, ll _y) : x(_x), y(_y) {}
  pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
  pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
  ll cross(const pt & p) const { return x * p.y - y * p.x; }
  ll dot(const pt & p) const { return x * p.x + y * p.y; }
  ll cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
  ll dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
  ll sqrLen() const { return this->dot(*this); }
};

vector <pt> hull[N], seq[N];
int size[N];
set <pair <int, int>> xy;

bool cmp(pt a, pt b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool lexComp(const pt & l, const pt & r){
  return l.x < r.x || (l.x == r.x && l.y < r.y);
}

bool pointInTriangle(pt a, pt b, pt c, pt point){
  ll s1 = abs(a.cross(b, c));
  ll s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
  return s1 == s2;
}

int sgn(long long val){
  return val > 0 ? 1 : (val == 0 ? 0 : -1);
}

void prepare(vector<pt> & points, int k){
  int n = points.size();
  int pos = 0;
  for(int i = 1; i < n; i++){
    if(lexComp(points[i], points[pos]))
      pos = i;
  }
  rotate(points.begin(), points.begin() + pos, points.end());

  n--;
  size[k] = n;
  seq[k].resize(n);
  for(int i = 0; i < n; i++)
    seq[k][i] = points[i + 1] - points[0];
}

bool pointInConvexPolygon(pt point, int i) {
  int n = size[i];
  if(seq[i][0].cross(point) != 0 && sgn(seq[i][0].cross(point)) != sgn(seq[i][0].cross(seq[i][n - 1])))
    return false;
  if(seq[i][n - 1].cross(point) != 0 && sgn(seq[i][n - 1].cross(point)) != sgn(seq[i][n - 1].cross(seq[i][0])))
    return false;

  if(seq[i][0].cross(point) == 0)
    return seq[i][0].sqrLen() >= point.sqrLen();

  int l = 0, r = n - 1;
  while(r - l > 1){
    int mid = (l + r)/2;
    int pos = mid;
    if(seq[i][pos].cross(point) >= 0)l = mid;
    else r = mid;
  }
  int pos = l;
  return pointInTriangle(seq[i][pos], seq[i][pos + 1], pt(0, 0), point);
}

void convex_hull(vector <pt>& a) {
  if (a.size() == 1)
    return;

  sort(a.begin(), a.end(), &cmp);
  pt p1 = a[0], p2 = a.back();
  vector<pt> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < (int)a.size(); i++) {
    if (i == a.size() - 1 || cw(p1, a[i], p2)) {
      while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
	up.pop_back();
      up.push_back(a[i]);
    }
    if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
      while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
	down.pop_back();
      down.push_back(a[i]);
    }
  }

  a.clear();
  for (int i = 0; i < (int)up.size(); i++)
    a.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; i--)
    a.push_back(down[i]);
}

int computeHull() {
  vector <pt> a;
  int layer = 0;
  while (xy.size()) {
    for (auto it : xy)
      a.push_back({it.first, it.second});
    convex_hull(a);
    for (auto it : a) {
      xy.erase(xy.find({it.x, it.y}));
      hull[layer].push_back({it.x, it.y});
      seq[layer].push_back({it.x, it.y});
    }
    prepare(a, layer);
    a.clear();
    layer++;
  }
  return layer;
}

int solve(int x, int y, int layer) {
  int i = 0;
  pt point = {x, y};
  while (i < layer && pointInConvexPolygon(point, i))
    i++;
  i--;
  return i;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m, q;
    xy.clear();
    scanf("%d%d", &m, &q);
    for (int i = 0; i < m; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      xy.insert({x, y});
      hull[i].clear();
      seq[i].clear();
    }
    int layer = computeHull();
    while (q--) {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%d\n", solve(x, y, layer));
    }
  }
  return 0;
}
