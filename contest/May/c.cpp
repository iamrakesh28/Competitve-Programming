#include <bits/stdc++.h>

#define N 400005
using namespace std;

long long arr[N], I;
int pre;

int main() {

	int n, k, K;
	cin>>n>>I;
	I = 8 * I;
	for (int i = 0; i < n; ++i)
		cin>>arr[i];
	sort(arr, arr + n);
	vector <int> dist, pref, suff;
	pre = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] != arr[i - 1]) {
			dist.push_back(pre);
			pre = 1;
		}
		else
			pre++;
	}
	dist.push_back(pre);
	K = dist.size();
	k = ceil(log2(K));
	if (n * k <= I) {
		puts("0");
		return 0;
	}
	int req = 1, cnt = 0, ans = 1e8;
	//cout<<req<<endl;
	//req = K - req;
	//cout<<req<<endl;
	for (int i = K; i >= 1; --i) {
		int test = ceil(log2(i));
		if (n * test <= I) {
			req = i;
			break;
		}
	}
	req = K - req;
	pref.push_back(0);
	suff.push_back(0);
	for (int i = 0; i < K; ++i)
		pref.push_back(pref[i] + dist[i]);
	for (int i = 0; i < K; ++i)
		suff.push_back(suff[i] + dist[K - i - 1]);
	for (int i = 0; i <= req; ++i) {
		int sum = pref[i] + suff[req - i];
		ans = min(ans, sum);
	}
	cout<<ans<<endl;
	return 0;
}
