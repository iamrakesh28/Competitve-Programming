#include <bits/stdc++.h>

void merge(long int **arr,long int l,long int m,long int r)
{
    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 =  r - m;
    long int L[n1][2], R[n2][2];
    for (i = 0; i < n1; i++)
    {
	L[i][0] = arr[l + i][0];
	L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
	   R[j][0] = arr[m + 1+ j][0];
	   R[j][1] = arr[m + 1+ j][1];
    }
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            arr[k][0] = L[i][0];
	    arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
	    arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k][0] = L[i][0];
	arr[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k][0] = R[j][0];
	arr[k][1] = R[j][1];
        j++;
        k++;
    }
}
void mergeSort(long int **arr,long int l,long int r)
{
    if (l < r)
    {
        long int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
inline void scanint(long int &x)

{
    register long int c = getchar_unlocked();

    x = 0;


    for(;((c<48 || c>57));c = getchar_unlocked());

    for(;c>47 && c<58;c = getchar_unlocked()) {x = (x<<1) + (x<<3) + c - 48;}

}

long int check(long int *final,long int n)
{
	for(long int i=0;i<n-1;++i)
	{
		if(final[i]>final[i+1])
		return i;
	}
	return -1;
}
int main()
{
	long int q;
	scanint(q);
	for(long int i=1;i<=q;++i)
	{
		long int n,*arr,**sort,*final,j=0,even,odd,val,x=0;
		scanf("%ld",&n);
		arr = (long int *)malloc(sizeof(long int)*n);
		final = (long int*)malloc(sizeof(long int)*n);
		sort = (long int **)malloc(sizeof(long int *)*n);
		for(j=0;j<n;++j)
		{
			sort[j] = (long int *)malloc(sizeof(long int)*2);
			scanint(x);
			sort[j][0] = arr[j] = x;
			sort[j][1] = j;
		}
		mergeSort(sort,0,n-1);
		even = n-2;
		odd = n-1;
		for(j=n-1;j>=0;--j)
		{
			if((n-1-sort[j][1])%2==0)                    //(j-sort[j][1])%2==0)
			{
				final[odd]=sort[j][0];
				odd-=2;
			}
			else
			{
				final[even]=sort[j][0];
				even-=2;
			}
		}
		val =check(final,n);
		printf("Case #%d: ",i);
		if(val == -1)
		{
			printf("OK\n");
		}
		else
		{
			printf("%ld\n",val);
		}
		
	}
	return 0;	
}
