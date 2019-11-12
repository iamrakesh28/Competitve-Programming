#include <iostream>

typedef unsigned long long ll;
using namespace std;

const int N = 1005;
ll arr[N];
int zero[61];

ll calc(ll k, int n, int j) {
	ll sum = 0;
	for (int r = j - 1; r >= 0; r--) {
		int one = n - zero[r];
		if (one >= zero[r])
			k = k | (1 << r);
	}
	for (int i = 0; i < n; ++i)
			sum = sum + (arr[i] ^ k);
	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i) {
		int n, poss = 1;
		ll m;
		cin>>n>>m;
		for (int j = 0; j < n; ++j)
			cin>>arr[j];
		ll ans = 0;
		for (int j = 0; j < 61; ++j)
			zero[j] = n;
		for (int j = 60; j >= 0; j--) {
			int one = 0;
			for (int r = 0; r < n; ++r)
				if (arr[r] & (1 << j))
					one++;
			zero[j] = n - one;
		}
		for (int j = 60; j >= 0; j--) {
			int one, zer;
			one = n - zero[j];
			zer = zero[j];
			if (one >= zer)
				ans = ans | (1 << j);
			else {
				ll sum = calc(ans | (1 << j), n, j);
				if (sum <= m)
					ans = ans | (1 << j);
			}
		}
		ll sum = calc(ans, n, 0);
		if (sum > m)
			poss = -1;
		cout<<"Case #"<<(i + 1)<<": ";
		if (poss == 1)
			cout<<ans<<"\n";
		else
			cout<<"-1\n";
	}
	return 0;
}
