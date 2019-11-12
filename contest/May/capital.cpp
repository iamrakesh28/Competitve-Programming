#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18, last = 1e9;
int n;
long long ans, k, prefix[300000], postfix[300000];
pair <long long, int> city[300000];

int main() {

	scanf("%d%ld", &n, &k);
	for (int i = 0; i < n; ++i) {
		long long c;
		scanf("%ld", &c);
		city[i].first = c;
		city[i].second = i;
	}
	if (n == 1) {
		printf("1 0\n");
		return 0;
	}
	sort(city, city + n);
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			prefix[i] = last - city[i].first;
			continue;
		}
		prefix[i] = prefix[i - 1] + last - city[i].first; 
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1) {
			postfix[i] = city[i].first;
			continue;
		}
		postfix[i] = postfix[i + 1] + city[i].first; 
	}
	long long val;
	ans = inf;
	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0)
			val = postfix[i + 1] - (n - i - 1) * city[i].first;
		else if (i == n - 1)
			val = prefix[i - 1] - i * (last - city[i].first);
		else
			val = postfix[i + 1] - (n - i - 1) * city[i].first + prefix[i - 1] - i * (last - city[i].first);
		if (val < k) {
			if ((k - val) % 2)
				val = 1;
			else
				val = 0;
		}
		else
			val = val - k;
		if (val < ans) {
			ans = val;
			ind = city[i].second;
		}
		else if (val == ans)
			ind = min(ind, city[i].second);
	}
	printf("%d %ld\n", ind + 1, ans);
	return 0;
}
