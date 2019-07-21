#include <bits/stdc++.h>

using namespace std;

int *par,*size,*group,n;

int root(int x)
{
	if(par[x] == x)
	return x;
	root(par[x]);
}

int enemyID(int x)
{
	return x+n;
}

void join(int u,int v)
{
	u = root(u);
	v = root(v);
	if(size[u] > size[v])
	{
		par[v] = u;
		size[u] += size[v];
	}
	else if(size[u] == size[v])
	{
		if(u < v)
		{
			par[v] = u;
			size[u] += size[v];
		}
		else
		{
			par[u] = v;
			size[v] += size[u];
		}
	}
	else
	{
		par[u] = v;
		size[v] += size[u];
	}
}

int max(int a,int b)
{
	return a>b ? a:b;
}

int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		par = new int[2*n];
		size = new int[2*n];
		group = new int[n];
		memset(group,0,sizeof(int)*n);
		for(int i=0;i<2*n;++i)
		{
			par[i] = i;
			size[i] = 1;
		}
		for(int i=0;i<n;++i)
		{
			int p,en;
			scanf("%d",&p);
			for(int j=0;j<p;++j)
			{
				scanf("%d",&en);
				en--;
				//join(enemyID(i),en);
				join(enemyID(en),i);
			}
		}
		for(int i=0;i<n;++i)
		group[root(i)]++;
		int invites = 0;
		for(int i=0;i<n;++i)
		{
			if(group[i] != -1)
			{
				invites += max(group[i],group[root(enemyID(i))]);
				group[i] = group[root(enemyID(i))] = -1;
			}
		//cout<<group[i]<<" ";
		}
		printf("%d\n",invites);
		delete [] par,size,group;
	}
	return 0;
}
