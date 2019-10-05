//10158

#include <bits/stdc++.h>

using namespace std;

int *country;
int root(int *parent,int node)
{
	if(parent[node] ==  node)
	return node;
	return root(parent,parent[node]);
}
void Union(int *parent,int *size,int u,int v)
{
	int u_root = root(parent,u);
	int v_root = root(parent,v);
	if(size[u_root] < size[v_root])
	{
		size[u_root] += size[v_root];
		parent[v_root] = u_root;
		if(country[u_root] == -1)
		country[u_root] = country[v_root];
	}
	else
	{
		size[v_root] += size[u_root];
		parent[u_root] = v_root;
		if(country[v_root] == -1)
		country[v_root] = country[u_root];
	}
}

int setFriend(int *parent,int *size,int x,int y)
{
	int x_root = root(parent,x);
	int y_root = root(parent,y);
	if(x_root == y_root)
	return 1;
	if(country[x_root] == -1 || country[y_root] == -1)
	Union(parent,size,x,y);
	else if(country[y_root] == country[x_root])
	return 1;
	else
	return -1;
	return 1;
}
int setEnemies(int *parent,int *size,int x,int y)
{
	int x_root = root(parent,x);
	int y_root = root(parent,y);
	if(x_root == y_root)
	return 0;
	if(country[x_root] == -1 || country[y_root] == -1)
	{
		if(country[x_root] == -1 && country[y_root] == -1)
		{
			country[x_root] = 0;
			country[y_root] = 1;
		}
		else if(country[x_root] == -1)
		country[x_root] = abs(country[y_root]-1);
		else
		country[y_root] = abs(country[x_root]-1);
	}
	else if(country[y_root] == country[x_root])
	return -1;
	return 1;
}
int areFriend(int *parent,int x,int y)
{
	int x_root = root(parent,x);
	int y_root = root(parent,y);
	if(country[x_root] == country[y_root])
	{
		if(country[x_root] == -1)
		{
			if(x_root == y_root)
			return 1;
			return 0;
		}
		else
		return 1;
	}
	return 0;
}
int areEnemies(int *parent,int x,int y)
{
	int x_root = root(parent,x);
	int y_root = root(parent,y);
	if(country[x_root] == country[y_root])
	return 0;
	if(country[x_root] != -1 && country[y_root] != -1)
	return 1;
	return 0;
}

int main()
{
	int n,c,x,y,ret;
	scanf("%d",&n);
	int *size = new int[n];
	int *parent = new int[n];
	country = new int[n];
	for(int i=0;i<n;++i)
	{
		size[i] = 1;
		parent[i] = i;
		country[i] = -1;
	}
	scanf("%d%d%d",&c,&x,&y);
	while(c)
	{
		switch(c)
		{
			case 1 : ret = setFriend(parent,size,x,y);
				 if(ret < 0)
				 cout<<ret<<endl; break;
			case 2 : ret = setEnemies(parent,size,x,y);
				 if(ret < 0)
				 cout<<ret<<endl; break;
			case 3 : ret = areFriend(parent,x,y);
				 cout<<ret<<endl; break;
			default : ret = areEnemies(parent,x,y);
				 cout<<ret<<endl; 
		}
		scanf("%d%d%d",&c,&x,&y);
	}
	return 0;
}
