#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double eps = 1e-9, r = 2.5;
vector <pair <double, double>> point;
vector <pair <double, int>> rad;

double norm(double a, double b) {
  return sqrt(a * a + b * b);
}

int main() {
  int t;
  char line[20];
  scanf("%d", &t);
  fgets(line, sizeof line, stdin);
  fgets(line, sizeof line, stdin);
  double pi = acos(-1);
  while (t--) {
    point.clear();
    while (fgets(line, sizeof line, stdin) != NULL) {
      if (line[0] == '\n')
	break;
      double xi, yi;
      scanf("%lf%lf", &xi, yi);
      point.push_back({xi, yi});
    }
    for (int i = 0; i < point.size() - 1; ++i) {
      for (int j = i + 1; j < point.size(); ++j) {
	if (point[i] == point[j]) {
	  rad.push_back({0, -1});
	  rad.push_back({2 * pi, 1});
	  continue;
	}
	double x1 = point[i].first, x2 = point[j].first,
	  y1 = point[i].second, y2 = point[j].second, c;
	c = norm(x1 - y1, x2 - y2);
	if (c > 2 * r + eps)
	  continue;
      }
    }
  }
  return 0;
}
