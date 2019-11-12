#include <bits/stdc++.h>

#define N 200000
using namespace std;

int x[N], x2[N], y[N], y2[N];
bool eff[N];
int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		eff[i] = false;	
	}
	for (int i = 0; i < m; ++i)
		scanf("%d%d", x2 + i, y2 + i);
	for (int i = 0; i < m; ++i) {
		
		int cnt = 0, ind;
		for (int j = 0; j < n; ++j) {
			if (abs(y[j] - y2[i]) <= x2[i] - x[j]) {
				cnt++;
				ind = j;
			}
			if (cnt >= 2)
				break;
		}
		//cout<<cnt<<" "<<ind + 1<<" "<<i+1<<endl;
		if (cnt == 1)
			eff[ind] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if(eff[i])
			cnt++;
	printf("%d\n", n - cnt);
	return 0;
}
