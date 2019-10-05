#include <stdio.h>
#include <stdlib.h>

long int minimum(long int a,long int  b,int *num)
{
	if(a <= b)
	{
		(*num) = 1;
		return a;
	}
	(*num) = 2;
	return b;
}

void merge(int *small,int *big,int size)
{
	for(int i=0;i<size;++i)
	big[i]=small[i];
	return ;	
}
void infinity(long int *arr,int n,int pos,int count,long int sum)
{
	int num;
	long int *min = (long int*)malloc(sizeof(long int)*count);
	int **seq = (int**)malloc(sizeof(int*)*count);
	int *size = (int*)malloc(sizeof(int)*count);
	for(int i=0;i < count; ++i)
	{
		int val = 2*i+pos;
		if(i >= 2)
		{
			if(i >= 3)
			{
				min[i]=minimum(min[i-2],min[i-3],&num)-2*arr[val];
				if(num==1)
				{
					 size[i]= size[i-2]+1;
					 seq[i] = (int *)malloc(sizeof(int)*size[i]);
					 merge(seq[i-2],seq[i],size[i]-1);
				
				}
				else
				{
					size[i] = size[i-3]+1;
					seq[i] = (int *)malloc(sizeof(int)*size[i]);
					merge(seq[i-3],seq[i],size[i]-1);
				}
				seq[i][size[i]-1] = val;
				free(seq[i-3]);
			}
			else
			{
				size[i]=2;
				min[i]=min[i-2]-2*arr[val];
				seq[i] = (int *)malloc(sizeof(int)*2);
				merge(seq[i-2],seq[i],1);
				seq[i][1] = val;
			}
		}
		else
		{
			size[i]=1;
			min[i]=sum-2*arr[val];
			seq[i] = (int *)malloc(sizeof(int)*1);
			seq[i][0]=val;
		}
	}
	int j=count-1;
	if(min[count-1] >= min[count-2])
	j=count-2;
	//printf("%ld= ",min[j]);
	for(int i=0;i<size[j];++i)
	{
		int val=seq[j][i];
		arr[val] -= 2*arr[val];
	}
	return;
}

void less(long int *arr, int n, long int *min,int *mark, int *ans,int *temp,int start,long int sum)
{
	long int val;
	if(start >= n)
	{
		if(sum < *min)
		{
			*min = sum;
			merge(temp,ans,n);
		}
		return ;
	}
	if(mark[start])
	{
	
		val = arr[start-1] - arr[start] + arr[start-2];
		if(start >=2 && temp[start-2] && val <= 0)
		{
			less(arr,n,min,mark,ans,temp,start+1,sum);
		}
		else
		{
			less(arr,n,min,mark,ans,temp,start+1,sum);
			arr[start] = -arr[start];
			sum += arr[start]; 
			temp[start]=1;
			less(arr,n,min,mark,ans,temp,start+1,sum);
			arr[start] = -arr[start];
			temp[start]=0;
		}
	}
	else
	less(arr,n,min,mark,ans,temp,start+1,sum);
	
}

void peak(long int *arr,int *mark,int n,long int *sum)
{
	long int val;
	if(arr[0] < arr[1])
	mark[0]=1;
	else
	mark[0]=0;
	for(int i=1;i<n-1;++i)
	{
		if(arr[i] < arr[i-1])
		{
			if(arr[i]<arr[i+1])
			mark[i]=1;
			else
			mark[i]=0;
		}
		else
		mark[i]=0;			
	}
	if(arr[n-1]<arr[n-2])
	mark[n-1]=1;
	else
	mark[n-1]=0;
	if(n>10)
	for(int i=0;i<n;++i)
	{
		if(mark[i])
		{
			if((i>=2) && mark[i-2])
			{
				val=arr[i-1] - arr[i] - arr[i-2];
				if(val <= 0)
				continue;
			}
			if((i<n-2) && mark[i+2])
			{
				val = arr[i+1] - arr[i] - arr[i+2];
				if(val <= 0)
				continue;
			}
			mark[i]=0;
			arr[i] = -arr[i];
			*sum = *sum-2*arr[i];
		}	
	}
	return ;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,count=0,pos,j;
		scanf("%d",&n);
		long int sum=0,*arr = (long int*)malloc(sizeof(long int)*n);
		int *mark = (int*)malloc(sizeof(int)*n);	
		for(int i=0;i<n;++i)
		{
			scanf("%ld",arr+i);
			sum += arr[i];
		}
		peak(arr,mark,n,&sum);
		if(n <= 10)
		{
			long int min=0;
			int *ans= (int *)calloc(n,sizeof(int));
			int *temp= (int *)calloc(n,sizeof(int));
			less(arr,n,&min,mark,ans,temp,0,0);
			for(int i=0;i<n;++i)
			{
				if(ans[i])
				printf("-%ld ",arr[i]);
				else
				printf("%ld ",arr[i]);
			}
			printf("\n");
			continue;
		}
		j=0;
		while(j<n)
		{
			if(mark[j])
			count++;
			else if(j>=2)
			{
				if(mark[j-2])
				{
				pos=j-2*count;
				infinity(arr,n,pos,count,sum);
				count=0;
				}
			}
			j++;
		}
		while(j<n+2)
		{
			if(j>=2)
			{
				if(mark[j-2])
				{
				pos=j-2*count;
				infinity(arr,n,pos,count,sum);
				count=0;
				}
			}
			j++;
		}
		for(int i=0;i<n;++i)
		{
			printf("%ld ",arr[i]);
		}
		printf("\n");
	}
	
}
