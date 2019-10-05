#include <iostream>
#include <bitset>
#include <vector>

#define N 70001
using namespace std;

int main() {

	int n, s, m = -1;
	bitset <4> cur(1);
	scanf("%d%d", &n, &s);
	vector <int> arr(n), ans(s + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		m = max(m, arr[i]);
	}
	for (int i = 0; i < n; ++i) {
		cur = cur | (cur << arr[i]);
		for (int j = 1; j <= s; ++j)
			if(!ans[j] && 
	}
	cout<<cur;
	return 0;
}
