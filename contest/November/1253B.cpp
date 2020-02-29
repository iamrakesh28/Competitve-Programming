#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int a[N], ans[N];

int main() {

	int n;
	scanf("%d", &n);
	set <int> s, help;
	int d = 0, poss = 1, val, cnt = 0;	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &val);
		if (s.find(val) != s.end()) {
			poss = 0;
			break;
		}
		if (val < 0) {
			val = -val;
			auto it = s.find(val);
			if (it == s.end()) {
				poss = 0;
				break;
			}
			s.erase(it);
		}
		else {
			auto it = s.find(val);
			if (it != s.end()) {
				poss = 0;
				break;
			}
			s.insert(val);
			it = help.find(val);

			if (it != help.end()) {
				poss = 0;
				break;
			}
			help.insert(val);
		}
		cnt++;
		if (s.size() == 0) {
			ans[d++] = cnt;
			cnt = 0;
			while (help.size())
				help.erase(help.begin());
		}
	}
	if (s.size())
		poss = 0;
	if (poss == 0) {
		puts("-1");
		return 0;
	}
	printf("%d\n", d);
	for (int i = 0; i < d; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}
