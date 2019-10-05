#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int pos(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'z')
		return c - 'a' + 10;
	else
		return c - 'A' + 36;

}

char A[63], W[50002], S[500001];
vector <int> pi[62];

int main() {

	int q, alp[62];
	scanf("%d", &q);
	while (q--) {
		scanf("%s%s%s", A, W, S);
		int a, w, s;
		a = strlen(A), w = strlen(W), s = strlen(S);
		W[w] = '#';
		w++;
		W[w] = '\0';
		for (int i = 0; i < a; ++i)
			alp[pos(A[i])] = i;
		for (int i = 0; i < a; ++i) {
			pi[i].resize(w);
			pi[i][0] = 0;
			for (int k = 1; k < w - 1; ++k) {
				int j = pi[i][k - 1];
				while (j > 0 && A[(alp[pos(W[j])] + i) % a] != A[(alp[pos(W[k])] + i) % a])
					j = pi[i][j - 1];
				if (A[(alp[pos(W[j])] + i) % a] == A[(alp[pos(W[k])] + i) % a])
					j++;
				pi[i][k] = j;
			}
			pi[i][w - 1] = 0;
		}
		vector <int> ans, temp;
		for (int i = 0; i < a; ++i) {
			int prev = 0, cnt = 0;
			for (int k = 0; k < s; ++k) {
				int j = prev;
				if (j == w - 1)
					j = pi[i][j - 1];
				while (j > 0 && A[(alp[pos(W[j])] + i) % a] != S[k])
					j = pi[i][j - 1];
				if (A[(alp[pos(W[j])] + i) % a] == S[k])
					j++;
				prev = j;
				//if (i == 0)
				//	cout<<j<<" ";
				if (j == w - 1)
					cnt++, temp.push_back(i);
			}
			if (cnt == 1) 
				for (int v : temp)
					ans.push_back(v);
			temp.clear();
			
		}
		if (ans.size() == 0)
			puts("no solution");
		else if (ans.size() == 1)
			printf("unique: %d\n", ans[0]);
		else {
			printf("ambiguous: ");
			for (int v = 0; v < ans.size() - 1; ++v)
				printf("%d ", ans[v]);
			printf("%d\n", ans[ans.size() - 1]);
		}
	}
	return 0;
}
