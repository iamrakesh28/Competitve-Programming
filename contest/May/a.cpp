#include <iostream>

using namespace std;

long long arr[100005];

int main() {
	int n, x, y;
	cin>>n>>x>>y;
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	for (int i = 0; i < n; ++i) {
		long long minx = 1e9 + 8;
		for (int j = 0; j < x && (i - j - 1) >= 0; ++j)
			minx = min(minx, arr[i - j - 1]);
		for (int j = 0; j < y && (i + j + 1) < n; ++j)
			minx = min(minx, arr[i + j + 1]);
		if (arr[i] < minx) {
			cout<<i+1<<endl;
			return 0;
		}
	}
	return 0;
}
