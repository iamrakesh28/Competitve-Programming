#include <bits/stdc++.h>

using namespace std;

bool visit[10000][10000];
int mat[10000][10000], dx[] = {0,0,-1,1};
int n,m,k;
int cost[10000][10000], dy[] = {1,-1,0,0};

class Cell{
	public:
	int row,col;
	int light;
	Cell(int x,int y,int L) : row(x), col(y), light(L)
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
		int r,c,s;
		r = p.row;
		c = p.col;
		s = p.light;
		visit[r][c] = true;
		if(s == 1) 
		{
			for(int d=2;d<4;++d)
			if(safe(r+dy[d],c+dx[d]) && visit[r+dy[d]][c+dx[d]] == false)
			{
				q.push_front(Cell(r+dy[d],c+dx[d],s));
				cost[r+dy[d]][c+dx[d]] = cost[r][c];
			}
		}
		else if(s == 2)
		{
			for(int d=0;d<2;++d)
			if(safe(r+dy[d],c+dx[d]) && visit[r+dy[d]][c+dx[d]] == false)
			{
				q.push_front(Cell(r+dy[d],c+dx[d],s));
				cost[r+dy[d]][c+dx[d]] = cost[r][c];
			}
		}	
		if(mat[r][c] == 0)
		continue;
		int y;
		for(int d=0;d<4;++d)
		if(safe(r+dy[d],c+dx[d]) && visit[r+dy[d]][c+dx[d]] == false)
		{
			if(mat[dy[d]+r][dx[d]+c] == 1)
			y = 0;
			else if(d < 2)
			{
				if(s == 2)
				y = 0;
				else
				s = 2, y = 1;
			}
			else
			{
				if(s == 1)
				y = 0;
				else
				s = 1, y = 1;
			}
			if(y)
			q.push_front(Cell(r+dy[d],c+dx[d],s));
			else
			q.push_back(Cell(r+dy[d],c+dx[d],s));
			cost[r+dy[d]][c+dx[d]] = cost[r][c] + y;
		}
	}
}
int main()
{
	memset(visit,false,sizeof visit);
	memset(mat,0,sizeof mat);
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
