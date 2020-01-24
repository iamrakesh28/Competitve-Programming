#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
bool torn[N];
int book[N];

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);
		for (int j = 0; j < n; ++j) {
			book[j] = 0;
			torn[j] = false;
		}
		for (int j = 0; j < m; ++j) {
			int p;
			scanf("%d", &p);
			torn[p - 1] = true;
		}
		set <int> s;
		multiset <int> help;
		for (int j = 0; j < q; ++j) {
			int mult;
			scanf("%d", &mult);
			s.insert(mult);
			help.insert(mult);
		}
		for (int it : s) {
			int c = help.count(it);
			for (int j = it - 1; j < n; j += it)
				book[j] = book[j] + c;
		}
		long long cnt = 0;
		for (int j = 0; j < n; ++j)
			if (torn[j] == false)
				cnt = cnt + book[j];
		printf("Case #%d: %ld\n", i + 1, cnt);
	}
}
