#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-9;
double PI;
vector <pair <double, int>> rad;

double norm(double a, double b) {
  return sqrt(a * a + b * b);
}

int sign(double x0, double y0, double r, double x, double y) {
  double val = (x - x0) * (x - x0) + (y - y0) * (y - y0) - r * r;
  if (val <= 0)
    return 1;
  return -1;
}
/*
double quad(double xi, double yi, double angle) {
  if (xi >= 0 && yi >= 0)
    return angle;
  if (xi < 0)
    return PI + angle;
  return 2 * PI + angle;
}

double perpend(double ax, double ay) {
  double tangle;
  if (abs(ax) < EPS) {
    if (ay >= 0)
      tangle = PI / 2;
    else
      tangle = 3 * PI / 2;
  }
  else
    tangle = quad(ax, ay, atan(ay / ax));
  return tangle;
}

void intersect(double a, double b, double c, double r) {
  double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
  //always intersect
  double d = r * r - c * c / (a * a + b * b);
  double mult = sqrt(d / (a * a + b * b));
  double ax, ay, bx, by;
  ax = x0 + b * mult;
  ay = y0 - a * mult;
  bx = x0 - b * mult;
  by = y0 + a * mult;
  double angle1 = perpend(ax, ay);
  double angle2 = perpend(bx, by);
  //cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
  if (angle1 < EPS) {
    if (angle2 > PI / 2 + EPS)
      angle1 = 2 * PI + angle1;
  }
  else if (angle2 < EPS) {
    if (angle1 > PI / 2 + EPS)
      angle2 = 2 * PI + angle2;
  }
  if (angle1 > angle2) {
    rad.push_back({angle2, -1});
    rad.push_back({angle1, 1});
  }
  else {
    rad.push_back({angle2, 1});
    rad.push_back({angle1, -1});
  }
}
*/
int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x0, y0, v, t;
  cin >> x0 >> y0 >> v >> t;
  int n;
  cin >> n;
  PI = acos(-1);
  double r = (double)v * t;
  for (int i = 0; i < n; ++i) {
    int xi, yi, ri;
    cin >> xi >> yi >> ri;
    double r1r2 = r + ri;
    double c1c2 = norm(xi - x0, yi - y0);
    //cout<<c1c2<<" "<<r<<endl;
    if (sign(xi, yi, ri, x0, y0) == 1) {
      puts("1");
      return 0;
    }
    if (c1c2 > r1r2 - EPS)
      continue;
    //if (abs(c1c2 - r1r2) < EPS)
    //  continue;
    xi = xi - x0;
    yi = yi - y0;
    double tangent = (double)xi * xi + (double)yi * yi - (double)ri * ri;
    tangent = sqrt(tangent);
    double ang, angL, angR, angM = atan2(yi, xi);
    if (angM < 0)
      angM += 2 * PI;
    //cout<<angM<<endl;
    if (tangent < r + EPS) {
      ang = asin(ri / c1c2);
      //cout<<ang * 180 / PI<<endl;
    }
    else {
      //cout<<i+1<<endl;
      //double d = 1.0 * xi * xi + 1.0 * yi * yi;
      ang = acos((c1c2 * c1c2 + r * r - (double)ri * ri) / (2 * c1c2 * r));
    }
    angL = angM - ang;
    angR = angM + ang;
    if (angL < 0) {
      rad.push_back({angL + 2 * PI, -1});
      rad.push_back({2 * PI, 1});
      rad.push_back({0.0, -1});
      rad.push_back({angR, 1});
    }
    else if (angR > 2 * PI) {
      rad.push_back({angL, -1});
      rad.push_back({2 * PI, 1});
      rad.push_back({0, -1});
      rad.push_back({angR - 2 * PI, 1});
    }
    else {
      rad.push_back({angL, -1});
      rad.push_back({angR, 1});
    }
  }
  sort(rad.begin(), rad.end());
  double ans = 0, prev;
  int cur = 0;
  for (auto it : rad) {
    //cout<<it.first * 180 / PI<<endl;
    if (it.second < 0) {
      cur++;
      if (cur == 1)
	prev = it.first;
    }
    else {
      cur--;
      if (cur == 0)
	ans = ans + it.first - prev;
    }
  }
  //cout << ans << endl;
  ans = ans / (2 * PI);
  printf("%0.11lf\n", ans);
  //cout << ans <<endl;
  return 0;
}
