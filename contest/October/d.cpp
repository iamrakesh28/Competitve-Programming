#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 3e5;
vector <int> arr[N];

bool is(int val) {
	for (int i = 1; i < arr[val].size(); ++i)
		if (arr[val][i - 1] != arr[val][i] - 1)
			return false;
	return true;
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, minm = 5e5, maxm = -1;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			arr[i].clear();	
		for (int i = 0; i < n; ++i) {
			int val;
			scanf("%d", &val);
			arr[val - 1].push_back(i);
			minm = min(minm, val);
			maxm = max(maxm, val);
		}
		if (is(minm - 1)) {
		}
		else {
		}
	}
	return 0;
}
