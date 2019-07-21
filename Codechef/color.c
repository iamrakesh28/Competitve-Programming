#include <stdio.h>
#include <stdlib.h>

void merge(long int *arr,long int l,long int m,long int r)
{
    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 =  r - m;
 
    long int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
	i=0;
	j=0;
	k=l;
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
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int *arr,long int l,long int r)
{
    if (l < r)
    {
        long int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 	merge(arr, l, m, r);
    }
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int n;
		long int count=0,prev,steps=0;
		scanf("%ld",&n);
		long int *arr=(long int *)malloc(sizeof(long int)*n);
		for(long int i=0;i<n;++i)
		{
			scanf("%ld",arr+i);
		}
		mergeSort(arr,0,n-1);
		prev=arr[0];
		//printf("%ld-",prev);
		for(long int i=1;i<n;++i)
		{
			if(prev==arr[i])
			{
				count++;
			}
			else
			{
				prev=arr[i];
				steps+=count;
				count=0;
			}
		}
		if(prev==arr[n-1])
		{
			if(count)
			{
				steps+=count;
			}
		}
		printf("%ld\n",steps);
	}
}
