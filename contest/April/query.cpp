#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int block, *arr, *color;
struct Query {
	int l, r, ind;
} q[N], ans[N];

bool compare(Query &a, Query &b)
{
	if (a.l / block != b.l / block)
		return a.l < b.l;
	else
		return a.r < b.r;
}

void solve(int n, int m, int k)
{
	sort(q, q + m, compare);
	int currL = 0, currR = 0, cnt = 0;
	color[arr[0]]++;
	if (color[arr[currL]] == k)
		cnt++;
	for (int i = 0; i < m; ++i) {
		int l = q[i].l, r = q[i].r;
		while (currL < l) {
			color[arr[currL]]--;
			if (color[arr[currL]] == k)
				cnt++;
			if (color[arr[currL]] == k - 1)
				cnt--;
			currL++;
		}
		while (currL >= l) {
			color[arr[currL]]++;
			if (color[arr[currL]] == k)
				cnt++;
			if (color[arr[currL]] == k + 1)
				cnt--;
			currL--;
		}
		while (currR <= r) {
			color[arr[currL]]++;
			if (color[arr[currR]] == k)
				cnt++;
			if (color[arr[currR]] == k + 1)
				cnt--;
			currR++;
		}
		while (currR > r) {
			color[arr[currR]]--;
			if (color[arr[currR]] == k)
				cnt++;
			if (color[arr[currR]] == k - 1)
				cnt--;
			currR--;
		}
		ans[q[i].ind].ind = cnt;
	}
}

int main() 
{
	int n, m, k;
	scanf("");
	block = sqrt(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d",&q[i].l, &q[i].r);
		q[i].ind = i;
		ans[i].l = q[i].l;
		ans[i].r = q[i].r;
	}
	return 0;
}
