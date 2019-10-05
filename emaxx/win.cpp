#include <bits/stdc++.h>

const int N = 1005;
using namespace std;

int player[N], villian[N];
int main()
{
	int q;
	scanf("%d",&q);
	while (q--) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i< n; ++i)
			scanf("%d", villian + i);
		for (int i = 0; i< n; ++i)
			scanf("%d", player + i);
		sort(villian, villian + n);
		sort(player, player + n);
		bool win = true;
		for (int i = 0; i< n; ++i)
			if (player[i] < villian[i]) {
				win = false;
				break;
			}
		if (win)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
}
