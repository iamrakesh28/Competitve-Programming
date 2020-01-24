#include <iostream>
#include <set>

using namespace std;

const int N = 55;
char s[N], t[N];
pair <int, int> ans[2 * N];
set <int> S[26], T[26];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		char ch = getchar();
		int i = 0;
		for (int j = 0; j < 26; ++j) {
			S[j].clear();
			T[j].clear();
		}
		while ((ch = getchar()) != '\n') {
			s[i++] = ch;
			S[ch - 'a'].insert(i - 1);
		}
		i = 0;
		while ((ch = getchar()) != '\n') {
			t[i++] = ch;
			T[ch - 'a'].insert(i - 1);
		}
		bool poss = true;
		for (int i = 0; i < 26; ++i) {
			if ((S[i].size() + T[i].size()) & 1) {
				poss = false;
				break;
			}
		}
		if (poss == false) {
			puts("NO");
			continue;
		}
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			int v = s[j] - 'a';
			S[v].erase(S[v].begin());
			if (s[j] == t[j]) {
				T[v].erase(T[v].begin());
				continue;
			}
			if (S[v].size()) {
				auto it = S[v].begin();
				int ind = *it;
				S[v].erase(it);
				S[t[j] - 'a'].insert(ind);
				s[ind] = t[j];
				t[j] = s[j];
				ans[cnt++] = {ind + 1, j + 1};
				continue;
			}
			auto it = T[v].begin();
			int ind = *it;
			T[v].erase(it);
			int u = s[j + 1] - 'a';
			S[u].erase(S[u].begin());
			T[t[j] - 'a'].erase(T[t[j] - 'a'].begin());
			S[t[j] - 'a'].insert(j + 1);
			T[u].insert(ind);
			t[ind] = s[j + 1];
			s[j + 1] = t[j];
			t[j] = s[j];
			ans[cnt++] = {j + 2, ind + 1};
			ans[cnt++] = {j + 2, j + 1};
		}
		puts("YES");
		printf("%d\n", cnt);
		for (int j = 0; j < cnt; ++j)
			printf("%d %d\n", ans[j].first, ans[j].second);
	}
	return 0; 
}
