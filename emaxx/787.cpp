#include <iostream>
#include <climits>

using namespace std;

int arr[100];

long long solve(int s, int e) {

	//cout<<s<<" "<<e<<endl;
	long long p1 = arr[s], p2 = arr[e], ans1 = INT_MIN, ans2 = INT_MIN;
	for (int i = s + 1; i <= e; ++i) {
		p1 = p1 * arr[i];
		ans1 = max(ans1, p1);
	}
	for (int i = e - 1; i >= s; --i) {
		p2 = p2 * arr[i];
		ans2 = max(ans2, p2);
	}
	return max(ans1, ans2);
}
int main() {

	int n = 0, x;
	while (scanf("%d", &x) != EOF) {
		if (x != -999999) {
			arr[n++] = x;
			continue;
		}
		int start = 0, m = INT_MIN;
		long long ans = m;
		for (int i = 0; i < n; ++i) {
			m = max(m, arr[i]);
			if (arr[i] != 0)
				continue;
			ans = max(ans, solve(start, i - 1));
			start = i + 1;
		}
		if (arr[n - 1] != 0)
			ans = max(ans, solve(start, n - 1));
		printf("%d\n", max(ans, (long long)m));
		n = 0;
	}
}
