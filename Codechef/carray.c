#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void sort(int **arr, int n)
{
	int swap;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if(arr[j][0]>arr[j+1][0])
			{
				swap=arr[j][0];
				arr[j][0]=arr[j+1][0];
				arr[j+1][0]=swap;
				swap=arr[j][1];
				arr[j][1]=arr[j+1][1];
				arr[j+1][1]=swap;
			}
		}
	}
}
*/
void merge(long int *arr,long int l,long int m,long int r)
{
    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 =  r - m;
 
    long int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long int *arr,long int l,long int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
void check(long int *arr,long int end,long int *heap,long int *arrcal)
{
	for(long int i=end-1;i>=0;--i)
	{
		if(arr[end]>=arrcal[i])
		{
			heap[end]+=heap[i];
			break;
		}
	}
}
long int calculate(long int *arr, long int n,long int *arrcal)
{
	long int max=1;
	long int *heap=(long int *)malloc(sizeof(long int)*n);
	//memset(heap,1,sizeof(int)*n);
	heap[0]=1;
	for(long int i=1;i<n;++i)
	{
		heap[i]=1;
		check(arr,i,heap,arrcal);
		if(heap[i]>max)
		max=heap[i];
		//printf("%d %d",max,heap[i]);
	}
	//printf("%d ",max);
	free(heap);
	return max;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int n,k,b;
		scanf("%ld%ld%ld",&n,&k,&b);
		long int *arr=(long int *)malloc(sizeof(long int )*n);
		long int *arrcal=(long int *)malloc(sizeof(long int )*n);
		for(long int i=0;i<n;++i)
		{
			scanf("%ld",arr+i);
			arrcal[i]=k*arr[i]+b;
		}
		//sort(arr,n);
		mergeSort(arr,0,n-1);
		mergeSort(arrcal,0,n-1);
		long int result=calculate(arr,n,arrcal);
		printf("%d\n",result);
	}
	return 0;
}
