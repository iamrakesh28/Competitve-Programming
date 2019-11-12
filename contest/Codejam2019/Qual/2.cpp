#include <bits/stdc++.h>

#define N 1000000
using namespace std;

int n;
char path[N],ans[N];
bool d[3][N], visit[3][N], dir[3][N], pos[3][N];
int dr[] = {1,0}, dc[] = {0,1};

pair <int,int> next(int ,int );

bool valid(int i,int j)
{
	if(i >= 0 && j >= 0 && i < n && j < n && abs(i-j) <= 1)
		return true;
	return false;
}

void dfs(int i, int j)
{
	bool dang;
	int cur, v;
	pair <int,int> p = next(i,j);
	cur = p.first, v = p.second;
	visit[cur][v] = true, dang = d[cur][v];
	for(int a = 0; a < 2; ++a) {
		int c,diff;
		p = next(i+dr[a],j+dc[a]);
		diff = p.first;
		c = p.second;
		if(valid(i+dr[a],j+dc[a]) && !(d[diff][c] && dang)) {
			if(!visit[diff][c])
				dfs(i+dr[a],j+dc[a]);
			if(pos[diff][c]) {
				pos[cur][v] = true;
				dir[cur][v] = a;
			}
		}
	}
	if(i == n-1 && j == n-1)
		pos[1][i] = true;
	return;
}


pair <int,int> next(int i,int j)
{
	int cur,v;
	if(i == j)
		cur = 1, v = i;
	else if(i > j)
		cur = 2, v = j;
	else
		cur = 0, v = i;
	return {cur,v};
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i = 0; i < q; ++i) {
		int r = 0,c = 0;
		scanf("%d",&n);
		pair <int,int> p;
		for(int j = 0; j < 3; ++j) {
			memset(d[j],false,sizeof(bool)*n);
			memset(visit[j],false,sizeof(bool)*n);
			memset(pos[j],false,sizeof(bool)*n);
		}
		p = next(r,c);
		d[p.first][p.second] = true;
		for(int j = 0; j < 2*n - 2; ++j) {
			scanf(" %c",path+j);
			if(path[j] == 'E')
				c += 1;
			else
				r += 1;
			if(abs(r-c) <= 1) {
				p = next(r,c);
				d[p.first][p.second] = true;
			}
		}
		/*for(int j = 0; j < 3; ++j) {
			for(int k=0;k<n;++k)
			cout<<d[j][k]<<" ";
			cout<<endl;
		}*/
		dfs(0,0);
		r = 0, c = 0;
		int diff = 0;
		printf("Case #%d: ",i+1);
		//cout<<dir[0][0]<<endl;
		while(!(r == n-1 && c == n-1)) {
			p = next(r,c);
			diff = dir[p.first][p.second];
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
