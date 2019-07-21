#include <bits/stdc++.h>

using namespace std;

bool visit[10000][10000];
int mat[10000][10000];
int n,m,k;
int cost[10000][10000];

class Cell{
	public:
	int row,col;
	int on;
	Cell(int x,int y,int On) : row(x), col(y), on(On)
	{}
};
bool safe(int row,int col)
{
	if(row < 0 || row >= n || col < 0 ||col >= m)
	return false;
	return true;
}
void BFS()
{
	Cell src(0,0,0);
	list<Cell> q;
	q.push_back(src);
	cost[0][0] = 0;
	while(!q.empty())
	{
		Cell p = q.front();
		q.pop_front();
		int r,c;
		r = p.row;
		c = p.col;
		visit[r][c] = true;
		if(safe(r-1,c) && visit[r-1][c] == false)
		{
			if(mat[r][c] == 1)
			{
				cost[r-1][c] = cost[r][c];
				if(mat[r-1][c] == 1)
				q.push_front(Cell(r-1,c,0));
				else
				{
					q.push_back(Cell(r-1,c,1));
					cost[r-1][c] += 1;
				}
			}
		}
		if(safe(r+1,c) && visit[r+1][c] == false)
		{
			if(mat[r][c] == 1)
			{
				cost[r+1][c] = cost[r][c];
				if(mat[r+1][c] == 1)
				q.push_front(Cell(r+1,c,0));
				else
				{
					q.push_back(Cell(r+1,c,1));
					cost[r+1][c] += 1;
				}
			}
		}
		if(safe(r,c-1) && visit[r][c-1] == false)
		{
			cost[r][c-1] = cost[r][c];
			if(mat[r][c-1] == 1)
			q.push_front(Cell(r,c-1,p.on));
			else
			{
				if(p.on == 1)
				q.push_front(Cell(r,c-1,1));
				else
				{
					q.push_back(Cell(r,c-1,1));
					cost[r][c-1] += 1;
				}
			}
		}
		if(safe(r,c+1) && visit[r][c+1] == false)
		{
			cost[r][c+1] = cost[r][c];
			if(mat[r][c+1] == 1)
			q.push_front(Cell(r,c+1,p.on));
			else
			{
				if(p.on == 1)
				q.push_front(Cell(r,c+1,1));
				else
				{
					q.push_back(Cell(r,c+1,1));
					cost[r][c+1] += 1;
				}
			}
		}
	}
}
int main()
{
	memset(visit,false,sizeof visit);
	memset(mat,false,sizeof mat);
	memset(cost,-1,sizeof cost);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mat[x-1][y-1]=1;
	}
	BFS();
	printf("%d\n",cost[n-1][m-1]);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		cout<<cost[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
