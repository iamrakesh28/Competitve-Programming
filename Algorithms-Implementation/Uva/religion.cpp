#include <iostream>

using namespace std;

int *par,*size;
bool *group;

int root(int x)
{
	if(par[x] == x)
	return x;
	return root(par[x]);
}

void join(int x,int y)
{
	x = root(x);
	y = root(y);
	if(x == y)
	return;
	if(size[x] > size[y])
	{
		par[y] = x;
		size[x] += size[y];
	}
	else
	{
		par[x] = y;
		size[y] += size[x];
	}
}

int main()
{
	int n,m,i=0;
	scanf("%d%d",&n,&m);
	while(n && m)
	{
		int rel=0;
		++i;
		par = new int[n];
		size = new int[n];
		group = new bool[n];
		for(int i=0;i<n;++i)
		{
			par[i] = i;
			size[i] = 1;
			group[i] = false;
		}
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			join(x-1,y-1);
		}
		for(int i=0;i<n;++i)
		group[root(i)] = true;
		for(int i=0;i<n;++i)
		{	
			if(group[i])
			rel++;
		}
		printf("Case %d: %d\n",i,rel);
		delete [] par,size,group;
		scanf("%d%d",&n,&m);
	}
	return 0;
}
