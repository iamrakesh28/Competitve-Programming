#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5;
vector <string> L;
int Alice[N], xA[26], xB[26], tA[26], tB[26];
pair <int, int> A[26], B[26];

bool isVowel(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': return true;
		default : return false;
	}
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int l, cnt1, cnt2, n, m = 0;
		scanf("%d", &l);
		L.resize(l);
		for (int i = 0; i < 26; ++i)
			tA[i] = tB[i] = xA[i] = xB[i] = 0;
		for (int i = 0 ; i < l; ++i) {
			cin>>L[i];
			Alice[i] = 1;
			for (int j = 0; j < L[i].size() - 1; ++j) {
				if (isVowel(L[i][j]) == false) {
					if (isVowel(L[i][j + 1]) == false) {
						Alice[i] = 0;
						m++;
						break;
					}
					if (j + 2 < L[i].size() && isVowel(L[i][j + 2]) == false) {
						Alice[i] = 0;
						m++;
						break;
					}
				}
			}
			set <int> s;
			for (auto c : L[i]) {
				s.insert(c - 'a');
				if (Alice[i])
					tA[c - 'a']++;
				else
					tB[c - 'a']++;
			}
			for (auto it : s)
				if (Alice[i])
					xA[it]++;
				else
					xB[it]++;
		}
		cnt1 = 0;
		n = l - m;
		for (int i = 0; i < 26; ++i) {
			if (xA[i])
				A[cnt1++] = {xA[i], 1};
			if (tB[i])
				A[cnt1++] = {tB[i], m};
		}
		cnt2 = 0;
		for (int i = 0; i < 26; ++i) {
			if (xB[i])
				B[cnt2++] = {xB[i], 1};
			if (tA[i])
				B[cnt2++] = {tA[i], n};
		}
		sort(A, A + cnt1);
		sort(B, B + cnt2);
		//for (int i = 0; i < cnt1; ++i)
			//cout<<A[i].first<<" "<<A[i].second<<endl;

		//for (int i = 0; i < cnt2; ++i)
			//cout<<B[i].first<<" "<<B[i].second<<endl;
		int a = cnt1 - 1, b = cnt2 - 1;
		double ans = A[a].first;
		A[a].second--;
		while (b >= 0) {
			//cout<<B[b].first<<" "<<B[b].second<<endl;
			ans = ans / B[b].first;
			B[b].second--;
			if (B[b].second == 0)
				b--;
			if (ans < 1e7) {
				if (A[a].second) {
					ans = ans * A[a].first;
					A[a].second--;
				}
				else {
					if (a > 0) {
						a--;
						ans = ans * A[a].first;
						A[a].second--;
					}
				}
			}
		}
		//cout<<ans<<endl;
		while (a > 0 || A[a].second) {
			if (A[a].second) {
				ans = ans * A[a].first;
				A[a].second--;
			}
			else {
				if (a > 0) {
					a--;
					ans = ans * A[a].first;
					A[a].second--;					
				}
			}
			if (ans >= 1e7)
				break;
		}
		if (ans >= 1e7)
			puts("infinity");
		else
			printf("%0.12lf\n", ans);
	}
	return 0;
}
