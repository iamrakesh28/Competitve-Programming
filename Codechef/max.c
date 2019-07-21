#include<stdio.h>
#include<stdlib.h>
 
void semisort(long 
int **arr, int n, int i, int m)
{
		for(int j=0;j<n-1-m;++j)
		{
			if(arr[i][j]>arr[i][j+1])
			{
				int temp=arr[i][j];
				arr[i][j]=arr[i][j+1];
				arr[i][j+1]=temp;
			}
		}
	return ;
}
 
long int suma(long int **arr, int n)
{
	long int sum=0,num,j;
	semisort(arr,n,n-1,0);
	sum+=arr[n-1][n-1];
	num=arr[n-1][n-1];
	for(int i=n-2;i>=0;--i)
	{
		int m=0;
		for(j=n-1;j>=0;--j)
		{
			semisort(arr,n,i,m);
			if(num>arr[i][j])
			{
				sum+=arr[i][j];
				num=arr[i][j];
				break;
			}
			m++;
		}
		if(j<0)
		{	
			sum=-1;
			break;
		}
	}
	return sum;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
                //printf("hello");
		int n;
		scanf("%d",&n);
		long int **arr=(long int **)malloc(sizeof(long int *)*n);
		for(int j=0;j<n;++j)
		{
			arr[j]=(long int *)malloc(sizeof(long int)*n);
			for(int k=0;k<n;++k)
			scanf("%ld",(*(arr+j)+k));
			//printf("hello");
		}
		long int sum=suma(arr,n);
		printf("%ld\n",sum);
		free(arr);
	}
	return 0;
}
