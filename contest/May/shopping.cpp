#include <bits/stdc++.h>

using namespace std;

int main() {
	
	long double x1, y1, x2, y2, r;
	scanf("%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2, &r);
	long double m = (y2 - y1) / (x2 - x1), c, d, ans;
	c = y1 - m * x1;
	d = abs(c) / sqrt(1 + m * m);
	if (d == r)
		ans = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
	else if (d < r) {
		long double l1, l2, c1, c2, c3, a1, a2, alpha;
		c1 = sqrt(x1 * x1 + y1 * y1);
		c2 = sqrt(x2 * x2 + y2 * y2);
		l1 = sqrt(c1 * c1 - r * r);
		l2 = sqrt(c2 * c2 - r * r);
		c3 = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
		a1 = asin(l1 / c1), a2 = asin(l2 / c2);
		alpha = (c1 * c1 + c2 * c2 - c3 * c3) / (2 * c1 * c2);
		//cout<<c1<<" "<<c2<<" "<<c3<<endl;
		alpha = acos(alpha);
		ans = l1 + l2 + r * (alpha - a1 - a2);
	}
	else {
		d = d - r;
		ans = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
		ans = ans / 2;
		ans = 2 * sqrt(ans * ans + d * d);
	}
	printf("%0.6Lf\n", ans);
}
