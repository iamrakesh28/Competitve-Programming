//10158

#include <bits/stdc++.h>

using namespace std;

int n,*parent;
int root(int node)
{
	if(parent[node] ==  node)
	return node;
	return root(parent[node]);
}
void Union(int *size,int u,int v)
{
	int u_root = root(u);
	int v_root = root(v);
	if(size[u_root] < size[v_root])
	{
		size[u_root] += size[v_root];
		parent[v_root] = u_root;
	}
	else
	{
		size[v_root] += size[u_root];
		parent[u_root] = v_root;
	}
}

int enemyID(int x)
{
	return n+x;
}

int setFriend(int *size,int x,int y)
{
	if(root(x) == root(enemyID(y)) || root(y) == root(enemyID(x)))
	return -1;
	Union(size,x,y);
	Union(size,enemyID(x),enemyID(y));
	return 1;	
}
int setEnemies(int *size,int x,int y)
{
	if(root(x) == root(y) || root(enemyID(y)) == root(enemyID(x)))
	return -1;
	Union(size,enemyID(x),y);
	Union(size,x,enemyID(y));
	return 1;
}
int areFriend(int x,int y)
{
	if(root(x) == root(y) || root(enemyID(x)) == root(enemyID(y)))
	return 1;
	return 0;
}
int areEnemies(int x,int y)
{
	if(root(enemyID(x)) == y || root(enemyID(y)) == x)
	return 1;
	return 0;
}

int main()
{
	int c,x,y,ret;
	scanf("%d",&n);
	int *size = new int[2*n];
	parent = new int[2*n];
	for(int i=0;i<2*n;++i)
	{
		size[i] = 1;
		parent[i] = i;
	}
	scanf("%d%d%d",&c,&x,&y);
	while(c)
	{
		switch(c)
		{
			case 1 : ret = setFriend(size,x,y);
				 if(ret < 0)
				 cout<<ret<<endl; break;
			case 2 : ret = setEnemies(size,x,y);
				 if(ret < 0)
				 cout<<ret<<endl; break;
			case 3 : ret = areFriend(x,y);
				 cout<<ret<<endl; break;
			default : ret = areEnemies(x,y);
				 cout<<ret<<endl; 
		}
		scanf("%d%d%d",&c,&x,&y);
	}
	return 0;
}
