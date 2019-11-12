#include <bits/stdc++.h>

#define N 100005
using namespace std;

long long arr[N];
int main() {

	int n, two = 0;
	long long sum = 0, ap;
	bool win = true, pos = false;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin>>arr[i], sum += arr[i];
	sort(arr, arr + n);
	if (n >= 2 && arr[0] == 0 && arr[1] == 0) {
		printf("cslnb\n");
		return 0;
	}
	for (int i = 1; i < n; ++i)
		if (arr[i] == arr[i - 1]) {
			two++;
			if (i >= 2 && abs(arr[i - 2] - arr[i]) >= 2)
				pos = true;
			else if (i < 2)
				pos = true;
		}
	if (two >= 2) {
		printf("cslnb\n");
		return 0;
	}
	if (two == 1 && pos == false) {
		printf("cslnb\n");
		return 0;
	}
	ap = n * (n - 1) /  2;
	if ((sum - ap) % 2) {
		printf("sjfnb\n");
		return 0;
	}
	else {
		printf("cslnb\n");
		return 0;
	}
	return 0;
}
