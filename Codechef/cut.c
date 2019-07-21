#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

long int maxVal(long int x,long int y) { return (x > y)? x: y; }
long int minVal(long int x,long int y) { return (x < y)? x: y; }
 
int getMid(int s, int e) {  return s + (e -s)/2;  }

long int RMQUtil_min(long int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return INT_MAX;
 
    int mid = getMid(ss, se);
    return minVal(RMQUtil_min(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil_min(st, mid+1, se, qs, qe, 2*index+2));
}
 
long int RMQ_min(long int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil_min(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil_min(long int *arr, int ss, int se, long int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil_min(arr, ss, mid, st, si*2+1),
                     constructSTUtil_min(arr, mid+1, se, st, si*2+2));
    return st[si];
}


long int RMQUtil(long int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return INT_MIN;
 
    int mid = getMid(ss, se);
    return maxVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
long int RMQ(long int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil(long int *arr, int ss, int se, long int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
long int *constructST(long int *arr, int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
 
    long int *st = (long int *)malloc(sizeof(long int)*max_size); 
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
long int *constructST_min(long int *arr, int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
 
    long int *st = (long int *)malloc(sizeof(long int)*max_size); 
    constructSTUtil_min(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
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

int find(int qs, int qe,long int *st,int n,long int value)
{
	long int large = RMQ(st, n, qs, qe);
	if(large <= value)
	return 1;
	else
	return 0;
}

int find_min(int qs, int qe,long int *st,int n,long int value)
{
	long int small = RMQ_min(st, n, qs, qe);
	if(small >= value)
	return 1;
	else
	return 0;
}
int ways(int start, int end,long int **final, long int *st, int n,long int *initial,long int *st_min)
{
	int count =0,check = 0;
	while(start < end)
	{
		if(!find(final[start][1],final[start+1][1],st,n,final[start][0]))
		{
			if(initial[final[start][1]] != final[start][0])
			count++;
			else
			{
				if(check)
				count++;
			}
			check =0;
		}
		else
		{
			//printf("gh");
			if(initial[final[start][1]] != final[start][0])
			check = 1;
			if(!find_min(final[start][1],final[start+1][1],st_min,n,final[start][0]))
			{
					count++;
			}
		}
		if(initial[final[start][1]] < final[start][0])
		return -1;
		start++;
	}
	if(initial[final[start][1]] < final[start][0])
	return -1;
	if(initial[final[start][1]] != final[start][0])
	count++;
	else
	{
		if(check)
		count++;
	}
	check =0;
	return count;
}

int cut_minimum(long int **final,long int *initial,int n,long int *st,long int *st_min)
{
	long int prev = final[n-1][0];
	int count=0,minimum=0,start,i,check ;
	for(i = n-2; i>=0 ;i--)
	{
		start = i;
		if(prev == final[i][0])
		{
			count++;
		}
		else
		{
			check =  ways(start+1,start+1+count,final,st,n,initial,st_min);
			if(check == -1)
			return -1;
			minimum += check;
			count = 0;
		}
		prev = final[i][0];
	}
	start = i;
	check =  ways(start+1,start+1+count,final,st,n,initial,st_min);
	if(check == -1)
	return -1;
	minimum += check;
	return minimum;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,min;
		scanf("%d",&n);
		long int *initial = (long int *)malloc(sizeof(long int)*n);
		long int *org = (long int *)malloc(sizeof(long int)*n);
		long int **final = (long int **)malloc(sizeof(long int*)*n);
		for(int i =0 ;i<n; ++i)
		{
			scanf("%ld",initial+i);
		}
		for(int i =0 ;i<n; ++i)
		{
			final[i] = (long int *)malloc(sizeof(long int)*2);
			scanf("%ld",final[i]+0);
			org[i] = final[i][0];
			final[i][1] = i;
		}
		mergeSort(final,0,n-1);
		long int *st_min,*st = constructST(org,n);
		st_min = constructST_min(initial,n);
		min = cut_minimum(final,initial,n,st,st_min);
		printf("%d\n",min);
	}
	return 0;
}
