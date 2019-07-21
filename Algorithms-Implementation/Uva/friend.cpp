#include <iostream>

using namespace std;

int *par,*size;

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

int maxi(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int q;;
	scanf("%d",&q);
	while(q--)
	{
		int max=0,n,m;
		scanf("%d%d",&n,&m);
		par = new int[n];
		size = new int[n];
		for(int i=0;i<n;++i)
		{
			par[i] = i;
			size[i] = 1;
		}
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			join(x-1,y-1);
		}
		for(int i=0;i<n;++i)
		max = maxi(size[root(i)],max);
		printf("%d\n",max);
		delete [] par,size;
	}
	return 0;
}
