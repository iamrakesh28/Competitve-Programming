#include <bits/stdc++.h>

using namespace std;

class Map{
	public:
	int row;
	int col;
	int dist;
	/*Map(int x,int y,int z)
	{
		row=y;
		col=x;
		dist=z;
	}*/
	Map(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};

int ** MinDist(char **grid,int n,int m,int source_row,int source_col)
{
	bool visited[n][m];
	int **dis=(int **)malloc(sizeof(int *)*n);
	for(int i=0;i<n;++i)
	{
		dis[i]=(int *)malloc(sizeof(int)*m);
		memset(dis[i],-1,sizeof(int)*m);
		for(int j=0;j<m;++j)
		{
			if(grid[i][j]=='*')
			visited[i][j]=true;
			else
			visited[i][j]=false;
		}
	}
	visited[source_row][source_col]=true;
	dis[source_row][source_col]=0;
	Map source(source_row,source_col,0);
	queue <Map> q;
	q.push(source);
	while(!q.empty())
	{
		Map p = q.front();
		q.pop();
		//up
		if(p.row-1>=0 && visited[p.row-1][p.col]==false)
		{
			q.push(Map(p.row-1,p.col,p.dist+1));
			visited[p.row-1][p.col]=true;
			dis[p.row-1][p.col]=p.dist+1;
		}
		//down
		if(p.row+1<n && visited[p.row+1][p.col]==false)
		{
			q.push(Map(p.row+1,p.col,p.dist+1));
			visited[p.row+1][p.col]=true;
			dis[p.row+1][p.col]=p.dist+1;
		}
		//right
		if(p.col+1<m && visited[p.row][p.col+1]==false)
		{
			q.push(Map(p.row,p.col+1,p.dist+1));
			visited[p.row][p.col+1]=true;
			dis[p.row][p.col+1]=p.dist+1;
		}
		//left
		if(p.col-1>=0 && visited[p.row][p.col-1]==false)
		{
			q.push(Map(p.row,p.col-1,p.dist+1));
			visited[p.row][p.col-1]=true;
			dis[p.row][p.col-1]=p.dist+1;
		}

	}
	return dis;
}

int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	char **grid=(char **)malloc(sizeof(char *)*n);
	for(int i=0;i<n;++i)
	{
		grid[i]=(char *)malloc(sizeof(char *)*m);
		scanf("%s",grid[i]);
	}
	int row,col;
	scanf("%d%d",&row,&col);
	int **dis=MinDist(grid,n,m,row-1,col-1);
	while(q--)
	{
		static int y,x;
		scanf("%d%d",&y,&x);
		printf("%d\n",dis[y-1][x-1]);
	}
	return 0;
}
