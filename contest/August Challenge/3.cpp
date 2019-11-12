#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {

	long long n, m, g;
	int q;
	cin>>n>>m>>q;
	g = gcd(n, m);
	while (q--) {
		long long sx, sy, ex, ey, seg1, seg2, l1, l2;
		cin>>sx>>sy>>ex>>ey;
		l1 = n / g;
		l2 = m / g;
		if (sx == 1)
			seg1 = (sy - 1) / l1;
		else
			seg1 = (sy - 1) / l2;
		if (ex == 1)
			seg2 = (ey - 1) / l1;
		else
			seg2 = (ey - 1) / l2;
		//cout<<seg1<<" "<<seg2<<endl;
		if (seg1 == seg2)
			puts("YES");
		else
			puts("NO");
		
	}
	return 0;
}
