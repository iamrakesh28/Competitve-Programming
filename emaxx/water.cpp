#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> ipair;

int chess[100][100];
int water[100][100];
bool visit[100][100];

int solve(int n,int m,int maxm)
{
	set <pair<int,ipair>> q;
	pair<int,ipair> p;
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	visit[i][j] = false;
	for(int i=0;i<n;++i)
	{
		q.insert(mk(chess[i][0],mk(i,0)));
		q.insert(mk(chess[i][m-1],mk(i,m-1)));
		water[i][0] = chess[i][0];
		water[i][m-1] = chess[i][m-1];
	}
	for(int i=0;i<m;++i)
	{
		q.insert(mk(chess[0][i],mk(0,i)));
		q.insert(mk(chess[n-1][i],mk(n-1,i)));
		water[0][i] = chess[0][i];
		water[n-1][i] = chess[n-1][i];
	}
	while(!q.empty())
	{
		p = *q.begin();
		q.erase(*q.begin());
		int r,c;
		r = p.second.first;
		c = p.second.second;
		visit[r][c] = true;
		if(r-1>=0 && visit[r-1][c] == false)
		{
			if(chess[r-1][c] <= water[r][c])
			water[r-1][c] = water[r][c];
			else
			water[r-1][c] = chess[r-1][c];
			q.insert(mk(water[r-1][c],mk(r-1,c)));
		}
		if(r+1<n && visit[r+1][c] == false)
		{
			if(chess[r+1][c] <= water[r][c])
			water[r+1][c] = water[r][c];
			else
			water[r+1][c] = chess[r+1][c];
			q.insert(mk(water[r+1][c],mk(r+1,c)));
		}
		if(c-1>=0 && visit[r][c-1] == false)
		{
			if(chess[r][c-1] <= water[r][c])
			water[r][c-1] = water[r][c];
			else
			water[r][c-1] = chess[r][c-1];
			q.insert(mk(water[r][c-1],mk(r,c-1)));
		}
		if(c+1<m && visit[r][c+1] == false)
		{
			if(chess[r][c+1] <= water[r][c])
			water[r][c+1] = water[r][c];
			else
			water[r][c+1] = chess[r][c+1];
			q.insert(mk(water[r][c+1],mk(r,c+1)));
		}
	}
	int vol = 0;
	for(int i=0;i<n;++i)
	for(int j=0;j<m;++j)
	vol += water[i][j]-chess[i][j];
	return vol;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m,maxm=-1;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				scanf("%d",chess[i]+j);
				maxm = max(maxm,chess[i][j]);
			}
		printf("%d\n",solve(n,m,maxm));
	}
	return 0;
}
