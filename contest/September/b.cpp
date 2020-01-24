#include <iostream>

using namespace std;

const int N = 2e5 + 5;
long long dp1[N], dp2[N];
int main() {

	int n;
	long long c, ne = 0, p = 0;
	scanf("%d", &n);
	// dp1 -> pos
	dp1[0] = 0;
	dp2[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin>>c;
		if (c > 0) {
			dp1[i + 1] = dp1[i] + 1;
			dp2[i + 1] = dp2[i];
		}
		else {
			dp1[i + 1] = dp2[i];
			dp2[i + 1] = dp1[i] + 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		p += dp1[i];
		ne += dp2[i];
	}
	cout<<ne<<" "<<p<<endl;
	return 0;
}
