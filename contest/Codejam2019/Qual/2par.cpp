#include <bits/stdc++.h>

#define N 5000
using namespace std;

int n;
char path[N];
bool d[N][N],visit[N][N], dirn[N][N], posn[N][N];
int dr[] = {1,0}, dc[] = {0,1};


bool valid(int i,int j)
{
	if(i >= 0 && j >= 0 && i < n && j < n)
		return true;
	return false;
}

void dfs(int i, int j)
{
	visit[i][j] = true;
	for(int a = 0; a < 2; ++a) {
		int r,c;
		r = i+dr[a];
		c = j+dc[a];
		if(valid(r,c) && !(d[r][c] && d[i][j])) {
			if(!visit[r][c])
				dfs(r,c);
			if(posn[r][c]) {
				posn[i][j] = true;
				dirn[i][j] = a;
			}
		}
	}
	if(i == n-1 && j == n-1)
		posn[i][j] = true;
	return;
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i = 0; i < q; ++i) {
		int r = 0,c = 0;
		scanf("%d",&n);
		for(int j = 0; j < n; ++j) {
			memset(d[j],false,sizeof(bool)*n);
			memset(visit[j],false,sizeof(bool)*n);
			memset(posn[j],false,sizeof(bool)*n);
		}
		d[r][c] = true;
		for(int j = 0; j < 2*n - 2; ++j) {
			scanf(" %c",path+j);
			if(path[j] == 'E')
				c += 1;
			else
				r += 1;
			d[r][c] = true;
		}
		dfs(0,0);
		r = 0, c = 0;
		printf("Case #%d: ",i+1);
		while(!(r == n-1 && c == n-1)) {
			int diff = dirn[r][c];
			if(diff) {
				printf("E");
				c += 1;
			}
			else { 
				printf("S");
				r += 1;
			}
			//cout<<r<<" "<<c<<endl;
		}
		printf("\n");
	}
}
