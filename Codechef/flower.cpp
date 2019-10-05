#include <bits/stdc++.h>

#define num 1000000
using namespace std;

class cell{
	public:
	int row,col;
	cell(int x,int y) : row(x),col(y) 
	{
	}
};

int max(int a,int b)
{
	return a>b?a:b;
}

void BFS(int **matrix,bool **visited,int **visit_org,int **visit_diff,int n,int m,int row,int col,int *sum)
{
	queue <cell> q;
	int val = matrix[row][col];
	cell obj(row,col);
	q.push(obj);
	visited[row][col]=true;
	visit_org[row][col]=matrix[row][col];
	visit_diff[row][col]=matrix[row][col];
	*sum = 1;
	while(!q.empty())
	{
		cell p = q.front();
		q.pop();
		if(p.row-1>=0 && visited[p.row-1][p.col] == false && matrix[p.row-1][p.col] == val)
		{
			visited[p.row-1][p.col] = true;
			visit_diff[p.row-1][p.col] = visit_org[p.row-1][p.col]=matrix[p.row-1][p.col];
			(*sum)++;
			q.push(cell(p.row-1,p.col));
		}
		if(p.row+1<n && visited[p.row+1][p.col] == false && matrix[p.row+1][p.col] == val)
		{
			visited[p.row+1][p.col] = true;
			visit_diff[p.row+1][p.col] = visit_org[p.row+1][p.col]=matrix[p.row+1][p.col];
			(*sum)++;
			q.push(cell(p.row+1,p.col));
		}
		if(p.col-1>=0 && visited[p.row][p.col-1] == false && matrix[p.row][p.col-1] == val)
		{
			visited[p.row][p.col-1] = true;
			visit_diff[p.row][p.col-1] = visit_org[p.row][p.col-1]=matrix[p.row][p.col-1];
			(*sum)++;
			q.push(cell(p.row,p.col-1));
		}
		if(p.col+1<m && visited[p.row][p.col+1] == false && matrix[p.row][p.col+1] == val)
		{
			visited[p.row][p.col+1] = true;
			visit_diff[p.row][p.col+1] = visit_org[p.row][p.col+1]=matrix[p.row][p.col+1];
			(*sum)++;
			q.push(cell(p.row,p.col+1));
		}
		
	}
	return ;
}

void DFS(int **matrix,int **visit_org,int **visit_diff,int n,int m,int row,int col,int org,int diff,int *freq,int *max)
{
		int temp;
		//printf("%d %d %d\n",row,col,org);
		if(freq[diff-1]+freq[org-1] > *max)
		*max = freq[diff-1]+freq[org-1];
		if(row-1>=0 && visit_org[row-1][col] == 0)
		{
			temp = diff;
			if(matrix[row-1][col] == diff || org == diff || matrix[row-1][col] == org)
			{	
				if(matrix[row-1][col] != org)
				{
					temp = visit_diff[row-1][col] = matrix[row-1][col];
					visit_org[row-1][col] = org;
				}
				else
				{
					visit_diff[row-1][col] = diff;
					visit_org[row-1][col] = org;
				}
				if(diff == org)
				freq[org-1]++;
				else
				freq[diff-1]++;
				DFS(matrix,visit_org,visit_diff,n,m,row-1,col,org,temp,freq,max);
			}
		}
		else if(row-1>=0 && visit_org[row-1][col] != matrix[row-1][col])
		{
		}
		if(row+1<n && (visit[row+1][col] != diff && visit[row+1][col] != org) )
		{
			temp = diff;
			if(matrix[row+1][col] == diff || org == diff || matrix[row+1][col] == org)
			{	
				if(matrix[row+1][col] != org)
				temp = visit[row+1][col] = matrix[row+1][col];
				else
				visit[row+1][col] = diff;
				freq[diff-1]++;
				DFS(matrix,visit,n,m,row+1,col,org,temp,freq,max);
			}
		}
		if(col-1>=0 && (visit[row][col-1] != diff && visit[row][col-1] != org) )
		{
			temp = diff;
			if(matrix[row][col-1] == diff || org == diff || matrix[row][col-1] == org)
			{	
				if(matrix[row][col-1] != org)
				temp = visit[row][col-1] = matrix[row][col-1];
				else
				visit[row][col] = diff;
				freq[diff-1]++;
				DFS(matrix,visit,n,m,row,col-1,org,temp,freq,max);
			}
		}
		if(col+1<m && (visit[row][col+1] != diff && visit[row][col+1] != org) )
		{
			temp = diff;
			if(matrix[row][col+1] == diff || org == diff || matrix[row][col+1] == org)
			{	
				if(matrix[row][col+1] != org)
				temp = visit[row][col+1] = matrix[row][col+1];
				else
				visit[row][col+1] = diff;
				freq[diff-1]++;
				DFS(matrix,visit,n,m,row,col+1,org,temp,freq,max);
			}
		}
}

void initial(int n,int m,int **visit)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		visit[i][j]=0;
	}
}

int main()
{
	int n,m,max=0;
	scanf("%d%d",&n,&m);
	int **arr = new int* [n];
	bool **visited = new bool* [n];
	int **visit_org = new int* [n];
	int **visit_diff = new int* [n];
	for(int i=0;i<n;++i)
	{
		arr[i] = new int[m];
		visited[i] = new bool[m];
		visit_org[i] = new int[m];
		visit_diff[i] = new int[m];
		for(int j=0;j<m;++j)
		{
			scanf("%d",arr[i]+j);
			visited[i][j] = false;
			visit_diff[i][j] = visit_org[i][j] = 0;
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(visited[i][j]==false)
			{
				int sum;
				int *freq = (int*)calloc(num,sizeof(int));
				BFS(arr,visited,visit_org,visit_diff,n,m,i,j,&sum);
				freq[arr[i][j]-1] = sum;
				DFS(arr,visit_org,visit_diff,n,m,i,j,arr[i][j],arr[i][j],freq,&max);
				//initial(n,m,visit);
				free(freq);
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
