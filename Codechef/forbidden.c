#include <stdio.h>
#include <stdlib.h>

/*int isSafe(int **arr,int n, int m, int x, int y)
{
	if((y<n)&&(y>=0)&&(x<m)&&(x>=0))
	{
		if(arr[y][x]!=-1)
		return 1;
		return 0;
	}
	else 
	return 0;
}*/

int backtrack(int **arr,int n, int m, int x, int y, int count)
{
	if((y<n)&&(y>=0)&&(x<m)&&(x>=0)&&arr[y][x]!=-1)
	{
		
			if(arr[y][x]>=count&&arr[y][x])
			{
				return 1;
			}
			int num=arr[y][x];
			arr[y][x]=-1;
			if(backtrack(arr,n,m,x,y+1,count+1))
			{
				arr[y][x]=num;
				return 1;
			}
			if(backtrack(arr,n,m,x,y-1,count+1))
			{
				arr[y][x]=num;
				return 1;
			}
			if(backtrack(arr,n,m,x+1,y,count+1))
			{
				arr[y][x]=num;
				return 1;
			}
			if(backtrack(arr,n,m,x-1,y,count+1))
			{
				arr[y][x]=num;
				return 1;
			}
			arr[y][x]=num;
			return 0;
	}
	else
	return 0;
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int **arr=(int **)malloc(sizeof(int *)*n);
		for(int j=0;j<n;++j)
		{
			arr[j]=(int *)malloc(sizeof(int)*m);
			for(int k=0;k<m;++k)
			{
				scanf("%d",arr[j]+k);
			}
		}
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<m;++k)
			{
				if(backtrack(arr,n,m,k,j,0))
				{
					printf("Y");
				}
				else if(arr[j][k]==-1)
					printf("B");
				else
					printf("N");
			}
			printf("\n");
		}
	}
	return 0;
}