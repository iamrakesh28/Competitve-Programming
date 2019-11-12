#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

const int N = 1e5 + 5, prime = 1e9 + 7;
char NL[N], NR[N];
int nr, diff, nl;
long long dp[N][4][11], dag[N][4][11], power[N];

int neg(int val) {
	if (val < 0)
		return 0;
	return NL[val] - '0';
}


long long solve(int i, int state, int digit) {
	if (i == nr) {
		dag[i][state][digit] = 1;
		return 0;
	}

	if (dp[i][state][digit] == -1) {
		long long val = 0, cnt = 0;
		int l, r;
		if (state == 0)
			l = 0, r = 9;
		else if (state == 1) {
			l = neg(i - diff), r = 9;
			if (digit != l) {
				val =  (val + solve(i + 1, 1, l)) % prime;
				val = (val + l * power[nr - 1 - i] * dag[i + 1][1][l] % prime) % prime;
			}
			else
				val =  (val + solve(i + 1, 1, l)) % prime;
			cnt = (cnt + dag[i + 1][1][l]) % prime;
			l++;
		}
		else if (state == 2) {
			l = 0, r = NR[i] - '0';
			if (digit != r) {
				val =  (val + solve(i + 1, 2, r)) % prime;
				val = (val + r * power[nr - 1 - i] * dag[i + 1][2][r] % prime) % prime;
			}
			else
				val =  (val + solve(i + 1, 2, r)) % prime;
			cnt = (cnt + dag[i + 1][2][r]) % prime;
			r--;
		}
		else {
			l = neg(i - diff), r = NR[i] - '0';
			if (l == r) {
				if (digit != l) {
					val =  (val + solve(i + 1, 3, l)) % prime;
					val = (val + l * power[nr - 1 - i] * dag[i + 1][3][l] % prime) % prime;
				}
				else
					val =  (val + solve(i + 1, 3, l)) % prime;
				cnt = (cnt + dag[i + 1][3][l]) % prime;
			}
			else {
				if (digit != l) {
					val =  (val + solve(i + 1, 1, l)) % prime;
					val = (val + l * power[nr - 1 - i] * dag[i + 1][1][l] % prime) % prime;
				}
				else
					val =  (val + solve(i + 1, 1, l)) % prime;
				
				cnt = (cnt + dag[i + 1][1][l]) % prime;
				if (digit != r) {
					val =  (val + solve(i + 1, 2, r)) % prime;
					val = (val + r * power[nr - 1 - i] * dag[i + 1][2][r] % prime) % prime;
				}
				else
					val =  (val + solve(i + 1, 2, r)) % prime;
				cnt = (cnt + dag[i + 1][2][r]) % prime;

			}
			l++, r--;
		}

		//cout<<l<<" "<<r<<" "<<i<<" "<<state<<" "<<digit<<" "<<val<<" ";
		for (int j = l; j <= r; ++j) {
			if (digit != j) {
				val =  (val + solve(i + 1, 0, j)) % prime;
				val = (val + j * power[nr - 1 - i] * dag[i + 1][0][j]) % prime;
			}
			else
				val =  (val + solve(i + 1, 0, j)) % prime;
			cnt = (cnt + dag[i + 1][0][j]) % prime;
		}
		//cout<<cnt<<endl;
		dp[i][state][digit] = val;
		dag[i][state][digit] = cnt;
	}
	return dp[i][state][digit];
}

int main() {

	int q;
	scanf("%d", &q);
	power[0] = 1;
	for (int i = 1; i < N; ++i)
		power[i] = power[i - 1] * 10 % prime;
	while (q--) {
		scanf("%d%s%d%s", &nl, NL, &nr, NR);
		diff = nr - nl;
		for (int i = 0; i <= nr; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 11; ++k)
					dp[i][j][k] = -1;
		long long ans = solve(0, 3, 10);
		assert(ans >= 0);
		printf("%lld\n", ans);
	}
	return 0;
}
