#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	vector <long long> fin;
	list <long long> arr;
	pair <long long, long long> ans[n];
	long long maxm = -1, ind = -1;
	for (int i = 0; i < n; ++i) {
		long long a;
		cin>>a;
		arr.push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		long long a, b;
		auto it = arr.begin();
		a = *it;
		it++;
		b = *it;
		if (a > b) {
			arr.erase(it);
			arr.push_back(b);
			ans[i].first = a;
			ans[i].second = b;
		}
		else {
			arr.erase(--it);
			arr.push_back(a);
			ans[i].first = a;
			ans[i].second = b;
		}
	}
	for (auto it : arr)
		fin.push_back(it);
	while (q--) {
		long long m;
		cin>>m;
		if (m <= n)
			cout<<ans[m - 1].first<<" "<<ans[m - 1].second<<endl;
		else {
			cout<<fin[0]<<" ";
			m = m - n - 1;
			m = m % (n - 1);
			cout<<fin[m + 1]<<endl;
		}
	}
	return 0;
}
