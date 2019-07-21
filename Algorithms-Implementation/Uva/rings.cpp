#include <bits/stdc++.h>

using namespace std;

int *parent,*size;
int root(int x)
{
	if(parent[x] == x)
	return x;
	return root(parent[x]);
}
void join(int x,int y)
{
	x = root(x);
	y = root(y);
	if(x != y)
	{
		if(size[x] < size[y])
		{
			parent[x] = y;
			size[y] += size[x];
		}
		else
		{
			parent[y] = x;
			size[x] += size[y];
		}
	}
}

float dist(float x1,float y1, float x2,float y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void rings(float *x,float *y,float *r,int n)
{	
	for(int i=0;i<n;++i)
	{
		for(int j = i+1;j<n;++j)
		{
			float center = dist(x[i],y[i],x[j],y[j]); 
			if(center < r[j] + r[i])
			{
				if(center > abs(r[j] - r[i]))
				join(i,j);
			}
		}
	}
}

int main()
{
	while(1)
	{
		int n,max=0;
		scanf("%d",&n);
		if(n == -1)
		break;
		float *x = new float[n];
		float *y = new float[n];
		float *r = new float[n];
		parent = new int[n];
		size = new int[n];
		for(int i=0;i<n;++i)
		{
			size[i] = 1;
			parent[i] = i;
			scanf("%f%f%f",x+i,y+i,r+i);	
		}
		rings(x,y,r,n);
		for(int i=0;i<n;++i)
		{
			if(size[i] > max)
			max = size[i];
		}
		delete [] x,y,r,parent,size;
		if(max == 1)
		printf("The largest component contains %d ring.\n",max);
		else
		printf("The largest component contains %d rings.\n",max);
	}
	return 0;
}
