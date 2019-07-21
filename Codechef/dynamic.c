#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void sort(int *arr, int j,int num)
{
    int beg=0,mid,end=j,temp;
    while(beg!=end)
    {
        mid=(beg+end)/2;
       if(num>arr[mid])
           beg=mid+1;
        else
            end=mid;
     }
        for(int i=j;i>=beg;--i)
            arr[i+1]=arr[i];
	if(num>arr[beg])
        arr[beg+1]=num;
	else
	arr[beg]=num;
}
void update(int *arr, int diff, int end,int val,int n)
{
	switch(diff)
	{
		case 3: diff=1;break;
		case 5: diff=3;break;
		case 7: diff=5;
	}
	for(int i=0;i<n;++i)
	{
	arr[i]+=diff;
	}
	arr[end]=val;//5/21+2/9 45+42=29/63
}
void check(int *arr,int start, int end, int *count,int n)
{
	int diff;
	diff=arr[end]-arr[start];
	if(diff)
	{
	(*count)++;
	if(diff<3)
	{	
	update(arr,3,end,arr[end],n);
	check(arr,start,end,count,n);
	}
	else
	if(diff<5)
	{
	update(arr,5,end,arr[end],n);
	check(arr,start,end,count,n);
	}
	else
	{
	update(arr,7,end,arr[end],n); 
	check(arr,start,end,count,n);  
	} 
	}

}
int rec(int *arr,int n)
{
    int start,count =0,end,i=1;
	start=0;
	while(i<n)
	{
	     if(arr[i]>arr[start])
		{
			end=i;
			check(arr,start,end,&count,n);
			start=i;
		}
		i++;
	}

      return count;
}
int main() {
    int q,count;
    scanf("%d",&q);
    for(int i=0;i<q;++i)
    {
        int n;
        scanf("%d",&n);
        int *arr=(int*)malloc(sizeof(int)*(n+1));
        scanf("%d",arr);
        for(int j=1;j<n;++j)
        {
            int num; //printf("hello");
            scanf("%d",&num);
            sort(arr,j-1,num);
        }
        //for(int i=0;i<n;++i)
	count=rec(arr,n);
        printf("%d",count);
    }
    return 0;
}
