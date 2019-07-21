#include <stdio.h>
#include <stdlib.h>

long int max(long int a, long int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

int check(long int **mat,int n,int m)
{
	/*if(mat[i+1][j]!=-1)
	{
		if(mat[i+1][j]<mat[i][j])
		return 1;
	}
	if(mat[i][j+1]!=-1)
	{
		if(mat[i][j+1]<mat[i][j])
		return 1;
	}*/
	for(int i=1;i<n+1;++i)
	{
		for(int j=2;j<m+1;++j)
		{
			if(mat[i][j]<mat[i][j-1])
			return -1;
			//if(check(mat,i,j))
			//return -1;
		}
	}
	for(int i=1;i<m+1;++i)
	{
		for(int j=2;j<n+1;++j)
		{
			if(mat[j][i]<mat[j-1][i])
			return -1;
			//if(check(mat,i,j))
			//return -1;
		}
	}
	return 0;
}

int fill(long int **mat,int n, int m)
{
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<m;++j)
		{
			if(mat[i][j]==-1)
			{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
			//if(check(mat,i,j))
			//return -1;
		}
	}
	for(int i=1;i<n;++i)
	{
		if(mat[i][m]==-1)
		{
			mat[i][m]=max(mat[i-1][m],mat[i][m-1]);
			/*if(mat[i+1][m]!=-1)
			{
				if(mat[i+1][m]<mat[i][m])
				return -1;
			}*/
		}
	}
	for(int i=1;i<m;++i)
	{
		if(mat[n][i]==-1)
		{
			mat[n][i]=max(mat[n-1][i],mat[n][i-1]);
			/*if(mat[n][i+1]!=-1)
			{
				if(mat[n][i+1]<mat[n][i])
				return -1;
			}*/
		}
	}
	if(mat[n][m]==-1)
	{
		mat[n][m]=max(mat[n-1][m],mat[n][m-1]);
	}
	if(check(mat,n,m)==-1)
	return -1;
	return 1;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long int **mat=(long int **)malloc(sizeof(long int*)*(n+1));
		for(int i=0;i<n+1;++i)
		{
			mat[i]=(long int*)malloc(sizeof(long int)*(m+1));
		}
		for(int i=1;i<n+1;++i)
		{
			for(int j=1;j<m+1;++j)
			{
				scanf("%ld",&mat[i][j]);
			}
		}
		for(int i=0;i<m+1;++i)
		{
			mat[0][i]=1;
		}
		for(int i=0;i<n+1;++i)
		{
			mat[i][0]=1;
		}
		if(fill(mat,n,m)==1)
		{
			for(int i=1;i<n+1;++i)
			{
				for(int j=1;j<m+1;++j)
				{
					printf("%ld ",mat[i][j]);
				}
				printf("\n");
			}
		}
		else
		printf("-1\n");
	}
	return 0;
}
