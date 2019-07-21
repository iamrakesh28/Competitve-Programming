#include <stdio.h>
#include <stdlib.h>

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

int mod(int a)
{
	if(a>0)
	return a;
	return -a;
}
int small(int a,int b)
{
	if(a<b)
	return a;
	return b;
}

int fake(long int **arr,int n,int s_pos,long int *act,int pos)
{
	int left=0,right=0,l_stock=0,r_stock=0,swap=0,lar,sm;
	int beg,end,mid;
	beg=0,end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(mid==pos)
		break;
		else if(act[mid]>arr[s_pos][0])
		{
			if(pos<mid)
			{
				r_stock--;	
				end = mid-1;
			}
			else
			{
				left++;//right++;
				beg = mid+1;
			}
		}
		else
		{
			if(pos>mid)
			{
				l_stock--;
				beg = mid+1;
			}
			else
			{
				right++;//left++;
				end = mid-1;
			}
		}
	}
	swap = small(left,right);
	lar = n-1-s_pos;
	sm = s_pos;
	lar = lar+r_stock-swap;
	sm = sm+l_stock-swap;
	if(small(lar,sm)>=mod(left-right))
	{
		swap+=mod(left-right);
	}
	else
	swap=-1;
	return swap;
}

int bin(long int **arr,int n,long int x,int *s_pos)
{
	int beg,end,mid;
	beg=0,end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid][0]==x)
		break;
		else if(arr[mid][0]>x)
		{
			end = mid-1;
		}
		else
		{
			beg = mid+1;
		}
	}
	*s_pos=mid;
	return arr[mid][1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		long int x;	
		scanf("%d%d",&n,&q);
		long int **arr = (long int **)malloc(sizeof(long int*)*n); 
		long int *act = (long int *)malloc(sizeof(long int)*n); 
		for(int i=0;i<n;++i)
		{
			arr[i] = (long int *)malloc(sizeof(long int)*2);
			scanf("%ld",arr[i]);
			arr[i][1]=i;
			act[i]=arr[i][0];
		}
		mergeSort(arr,0,n-1);
		while(q--)
		{
			int pos,s_pos,swap;
			scanf("%ld",&x);
			pos=bin(arr,n,x,&s_pos);
			swap=fake(arr,n,s_pos,act,pos);
			printf("%d\n",swap);
		}
	}
	return 0;
}
