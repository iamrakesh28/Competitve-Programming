#include <stdio.h>
#include <stdlib.h>


void Sort(long int **sort, int n, long int *arr)
{
		long int large = arr[0];
		for(int j = 0 ; j < n; ++j)
		{
			if(arr[j] >= large)
			{
				large = arr[j];
				sort[n-1][0] = arr[j];
				sort[n-1][1] = j;
			}
		}
}

void inverse(long int *arr, int start, int end)
{
	int n =end-start;
	long int val;
	for(int i = 0 ; i  <= n/2  ; ++i)
	{
		val = arr[i + start];
		arr[i + start] = arr[end - i];
		arr[end-i] = val;
	}
}
int main()
{
		long int n,**sort,*arr,minimum=0,j;
		scanf("%ld",&n);
		sort = (long int **)malloc(sizeof(long int *)*n);
		arr = (long int *)malloc(sizeof(long int )*n);
		for(j=0;j<n;++j)
		{
			sort[j] = (long int *)malloc(sizeof(long int)*2);
			scanf("%ld",arr+j);
		}
		for(j = n-1; j >= 0; --j)
		{
			Sort(sort,j+1,arr);
			if(sort[j][1] != j)
			{
				inverse(arr,sort[j][1],j);
				minimum++;
			}
		}
		printf("%ld\n ",minimum);
	return 0;	
}
