#include <bits/stdc++.h>

using namespace std;

char rob[300][600];
int len[300];
char ans[500];
bool rem[300];
void RM(int k, char c, int a) {
	for (int i = 0; i < a; ++i) {
		if (rem[i] == false) {
			int m = k % len[i];
			if (rob[i][m] != c)
				rem[i] = true;
		}
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i) {
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j) {
			scanf("%s",rob[j]);
			len[j] = strlen(rob[j]);
			rem[j] = false;
		}
		bool win = true;
		int k;
		for(k = 0; k <= 256; ++k) {
			bool p = false, s = false, st = false;
			for (int j = 0; j < a; ++j) {
				if (rem[j] == true)
					continue;
				int m = k % len[j];
				if (rob[j][m] == 'P')
					p = true;	
				else if (rob[j][m] == 'R')
					st = true;
				else
					s = true;
			}
			if (p && st && s) {
				win = false;
				break;
			}
			if (p && st) {
				ans[k] = 'P';
				RM(k, 'P' ,a);
			}
			else if (p && s) {
				ans[k] = 'S';
				RM(k, 'S' ,a);
			}
			else if (s && st) {
				ans[k] = 'R';
				RM(k, 'R' ,a);
			}
			else {
				win = true;
				if (p)
				ans[k] = 'S';
				else if (st)
				ans[k] = 'P';
				else	
				ans[k] = 'R';
				break;
			}
		}
		if (win) {
			printf("Case #%d: ",i + 1);
			for (int m = 0; m <= k; ++m)
				printf("%c",ans[m]);
			printf("\n");
		}
		else
			printf("Case #%d: IMPOSSIBLE\n",i + 1);
	}
	return 0;
}
