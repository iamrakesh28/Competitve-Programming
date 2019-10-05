#include <bits/stdc++.h>

using namespace std;

class Cell{
	public:
	int row,col;
	Cell(int x,int y): row(x),col(y){}
};
char maze[21][21];
int r,c;
bool visit[20][20];
bool valid(int n,int m)
{
	int cnt=0;
	for(int i=0;i<m;++i)
	{
		if(maze[0][i] == '.')
		{
			r = 0,c = i;
			cnt++;
		}
		if(maze[n-1][i] == '.' && 0 != n-1)
		{
			r = n-1,c = i;
			cnt++;
		}	
	}
	for(int i=1;i<n-1;++i)
	{
		if(maze[i][0] == '.')
		{
			r = i,c = 0;
			cnt++;
		}
		if(maze[i][m-1] == '.' && 0 != m-1)
		{
			r = i,c = m-1;
			cnt++;
		}
	}
	if(cnt == 2)
	return true;
	return false;
}
bool BFS(int n,int m)
{
	queue <Cell> q;
	q.push(Cell(r,c));
	memset(visit,false,sizeof visit);
	while(!q.empty())
	{
		Cell p = q.front();
		q.pop();
		visit[p.row][p.col] = true;
		if(p.row-1 >=0 && visit[p.row-1][p.col] == false && maze[p.row-1][p.col] == '.')
		{
			q.push(Cell(p.row-1,p.col));
			if(p.row == 1 || p.col == 0 || p.col == m-1)
			return true;
		}
		if(p.row+1 < n && visit[p.row+1][p.col] == false && maze[p.row+1][p.col] == '.')
		{
			q.push(Cell(p.row+1,p.col));
			if(p.row == n-2 || p.col == 0 || p.col == m-1)
			return true;
		}
		if(p.col-1 >=0 && visit[p.row][p.col-1] == false && maze[p.row][p.col-1] == '.')
		{
			q.push(Cell(p.row,p.col-1));
			if(p.col == 1 || p.row == 0|| p.row == n-1)
			return true;
		}
		if(p.col+1 < m && visit[p.row][p.col+1] == false && maze[p.row][p.col+1] == '.')
		{
			q.push(Cell(p.row,p.col+1));
			if(p.col == m-2 || p.row == 0|| p.row == n-1)
			return true;
		}
	}
	return false;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		scanf(" %c",maze[i]+j);
		if(valid(n,m)==false)
		{
			printf("invalid\n");
			continue;
		}
		if(BFS(n,m)==true)
		printf("valid\n");
		else
		printf("invalid\n");
	}
	return 0;
}
