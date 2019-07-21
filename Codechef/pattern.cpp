#include <bits/stdc++.h>

using namespace std;

struct point{
	int x,y;
};

class Graph{

	public:
	list <int> *adj;
	void GenerateGraph(point *,int);
	int ModifiedDFS(int,bool *);
	int Not_present(int,int);
};

int collinear(int i,int j, int k, point *points)
{
	float m1,m2;
	int check = 1;
	if(points[j].x == points[i].x)
	{
		check  = 0;
		if(points[k].x == points[i].x)
		m1 = m2;
		else
		return 0;
	}
	if(points[k].x == points[i].x)
	{
		check = 0;
		if(points[j].x == points[i].x)
		m1 = m2;
		else
		return 0;
	}
	if(check)
	{
		m1 = (points[j].y - points[i].y)/(points[j].x - points[i].x);
		m2 = (points[k].y - points[i].y)/(points[k].x - points[i].x);
		//m1 = abs(m1);
		//m2 = abs(m2);
	}
	if(m1 == m2)
	{
		int d1,d2,d3;
		d1 = (int)pow((points[i].x - points[j].x),2) + (int)pow((points[i].y - points[j].y),2);
		d2 = (int)pow((points[i].x - points[k].x),2) + (int)pow((points[i].y - points[k].y),2);
		d3 = (int)pow((points[j].x - points[k].x),2) + (int)pow((points[j].y - points[k].y),2);
		d1 = sqrt(d1);
		d2 = sqrt(d2);
		d3 = sqrt(d3);
		//printf("%d %d\n",d1+d2,d3);
		if(d1+d2 == d3)
		return 0;
		if(d1 < d2)
		return 0;
		else
		return 1;
	}
	else
	return 0;
}

void Graph :: GenerateGraph(point *points, int n)
{
	int flag;
	adj = new list < int > [n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==j)
			continue;
			flag = 1;
			for(int k=0;k<n;++k)
			{
				if(k==i || k == j)
				continue;
				if(collinear(i,j,k,points))
				{
					flag = 0;
					//printf("%d %d %d\n",i,j,k);
					break;
				}
			}
			if(flag == 1)
			{
				//printf("%d %d\n",i,j);
				adj[i].push_back(j);
			}
		}
	}
}

int Graph :: Not_present(int leaf,int node)
{
	list <int> :: iterator it;
	if(leaf == node)
	return 0;
	for(it = adj[node].begin();it != adj[node].end();it++)
	{
		if(*it == leaf)
		return 0;
	}
	return 1;
}

int Graph :: ModifiedDFS(int node,bool *visited)
{
	int count=0;
	visited[node] = true;
	count++;
	//printf("%d-",node);
	list <int> :: iterator it,it1;
	for(it = adj[node].begin(); it != adj[node].end(); ++it)
	{
		if(visited[*it] == false)
		{
			count += ModifiedDFS(*it,visited);
		}
		else
		{
			for(it1 = adj[*it].begin(); it1 != adj[*it].end(); ++it1)
			{
				if(Not_present(*it1,node))
				adj[node].push_back(*it1);
			}
		}
	}
	visited[node] = false;
	return count;
}

int calculate(point *points,int n)
{
	Graph tree;
	int count=0;
	tree.GenerateGraph(points,n);
	bool *visited = new bool[n];
	for(int i=0;i<n;++i)
	{
		memset(visited,false,sizeof(bool)*n);
		count += tree.ModifiedDFS(i,visited) -1 ;	
	}
	return count;
}

int main()
{
	int n;
	scanf("%d",&n);
	point *points = new point[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&points[i].x,&points[i].y);
	}
	int count = calculate(points,n);
	printf("%d\n",count);
	return 0;
}
