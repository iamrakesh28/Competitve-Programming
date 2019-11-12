#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int l[N], r[N], v[N], val[N];
pair <int, int> arr[N];

void solve(int n) {

	for (int i = 0; i < n; ++i) {
		int cnt = 0, cn = 0;
		for (int j = 0; j < n; ++j)
			if (v[i] == v[j])
				val[cnt++] = j;
		for (int j = 0; j < cnt; ++j) {
			arr[cn++] = {l[val[j]], -1};	
			arr[cn++] = {r[val[j]], 1};
		}
		sort(arr, arr + cn);
		cnt = 0;
		//cout<<cn<<endl;
		for (int j = 0; j < cn; ++j) {
			//cout<<arr[j].first<<endl;
			if (arr[j].second == -1)
				cnt++;
			else
				cnt--;
			//cout<<cnt<<endl;
			if (cnt >= 3) {
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d%d", l + i, r + i, v + i);
		solve(n);
	}
	return 0;
}
