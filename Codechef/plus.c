#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculation(int **arr,int n,int m,int row,int col)
{
	int i,j,cal,max=0;
	for(i=1;i<n-1;++i)
	{
		for(j=1;j<m-1;++j)
		{
			if(abs(row-i) >=2 || abs(col-j) >=2 )
			{
				cal = arr[row][col]*arr[i][j] + arr[row-1][col]*arr[i-1][j] +arr[row+1][col]*arr[i+1][j] +arr[row][col-1]*arr[i][j-1] +arr[row][col+1] * arr[i][j+1];
				if(cal > max)
				max = cal;
			}
		}
	}
	return max;
}

int main()
{
	int n,m,i,j,max=0,cal;
	scanf("%d%d",&n,&m);
	int **arr = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;++i)
	{
		arr[i] = (int*)malloc(sizeof(int)*m);
		for(j=0;j<m;++j)
		scanf("%d",arr[i]+j);
	}
	for(i=1;i<n-1;++i)
	{
		for(j=1;j<m-1;++j)
		{
			cal=calculation(arr,n,m,i,j);
			if(cal>max)
			max=cal;
		}
	}
	printf("%d\n",max);
	return 0;
}
