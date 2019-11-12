#include <bits/stdc++.h>

using namespace std;

int p, qx[100005], qy[100005], xi, yi;

int main()
{
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i) {
		int q;
		scanf("%d%d",&p,&q);
		xi = 0;
		yi = 0;
		memset(qx,0,sizeof(int)*(q+5));
		memset(qy,0,sizeof(int)*(q+5));
		for (int j = 0; j < p; ++j) {
			int x, y;
			char d;
			scanf("%d%d %c",&x,&y,&d);
			if (d == 'E') {
				qx[x+1]++;
			}
			else if(d == 'W') {
				qx[0]++;
				qx[x]--;
			}
			else if (d == 'N') {
				qy[y+1]++;
			}
			else {
				qy[y]--;
				qy[0]++;
			}
		}
		for (int i = 1; i <= q; ++i) {
			qx[i] += qx[i-1];
			qy[i] += qy[i-1];
		}
		int vx = -1, vy = -1,xa,ya;
		for (int i = 0; i <= q; ++i) {
			if (vx < qx[i]) {
				vx = qx[i];
				xa = i;
			}
			if (vy < qy[i]) {
				vy = qy[i];
				ya = i;
			}
		}
		printf("Case #%d: %d %d\n",i+1,xa,ya);
	}
	return 0;
}
