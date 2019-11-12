#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n, p, w, d;
	cin>>n>>p>>w>>d;
	long long x, y, g;
	bool pos = find_any_solution(w, d, p, x, y, g);
	if (pos == false)
		puts("-1");
	else {
		if (x < 0 || y < 0) {
			if (x < 0 && y < 0) {
				puts("-1");
			else if (x < 0) {
				
			}
		}
		else {
			if (x + y > n)
				puts("-1");
			else
				cout<<x<<" "<<y<<" "<<(n - x - y)<<endl;
		}
	}
	return 0;
}
