#include <iostream>
#include <cmath>
#include <queue>
#include <cassert>

#define N 1000005
using namespace std;

const int inf = 1e9;
int arr[N], temp[N];

int solve(int n, int pos) {
	queue <int> q;
	for (int i = 0; i < pos; ++i)
		q.push(i);
	q.push(-1);
	for (int i = pos; i < n - 1; ++i)
		q.push(i);
	long long d = 0;
	int a, b;
	while (q.size() > 2) {
		a = q.front();
		q.pop();
		if (a == -1) {
			a = q.front();
			q.pop();
			b = q.front();
			q.pop();
			q.push(-1);
			q.push(a);
		}
		else {
			b = q.front();
			q.pop();
			if (b == -1) {
				q.push(a);
				q.push(b);
				//cout<<arr[a]<<endl;
				d += arr[a];
			}
			else
				q.push(a);
		}
	}
	return d;
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, f, m = inf;
		scanf("%d", &n);
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d", arr + i);
			m = min(m, arr[i]);
			if ((i & 1) == 0)
				temp[i / 2] = arr[i];
		}
		scanf("%d", &f);
		if (m > f) {
			puts("impossible");
			continue;
		}
		int ans = inf;
		int p;
		for (int i = 0; i < n; ++i) {
			int d = 0;
			//cout<<i+1<<" "<<d<<endl;
			d += solve(n, i);
			cout<<i<<" "<<d<<endl;
			
			if (d + f < ans && f >= arr[i % (n - 1)]) {
				p = i;
				ans = d + f;
			}
		}
		puts("possible");
		printf("%d %d\n", p + 1, ans);
		
	}
	return 0;
}
