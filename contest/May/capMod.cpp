#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	pair <int, int> *city = new pair <int, int> [n];
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		city[i].first = c;
		city[i].second = i;
	}
	sort(city, city + n);
	int med;
	if (n % 2)
		med = n / 2;
	else {
		if (city[n / 2 - 1].second < city[n /2].second)
			med = n / 2 - 1;
		else
			med = n / 2;
	}
	for (int i = 0; i < n; ++i) {
		if (city[i].first == city[med].first && city[i].second < city[med].second)
			med = i;
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i)
		sum = sum + (long long)abs(city[i].first - city[med].first);
	//cout<<med<<" "<<city[med].first<<" "<<city[med].second<<endl;
	long long ans = sum - k;
	if (ans < 0) {
		long long rem = k - sum;
		if (rem % 2)
			ans = 1;
		else
			ans = 0;
	}
	printf("%d %ld\n", city[med].second + 1, ans);
	return 0;
}
