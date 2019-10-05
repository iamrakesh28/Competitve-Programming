#include <bits/stdc++.h>

using namespace std;

long int min(long int a,long int b)
{
	return a<b?a:b;
}
long int max(long int a,long int b)
{
	return a>b?a:b;
}

long int interval(int begin,long int *arr,int n)
{
	long int smallest,small,largest,count=0;
	if(begin+2 >= n)
	return 0;
	smallest = min(arr[begin],arr[begin+1]);
	largest = max(arr[begin],arr[begin+1]);
	if(arr[begin+2] > largest)
	largest = arr[begin+2];
	else if(arr[begin+2] < smallest)
	{
		small = smallest;
		smallest = arr[begin+2];
	}
	else
	small = arr[begin+2];
	if(small+smallest >= largest)
	count++;
	else
	return 0;
	
}

int main()
{
	int n;
	scanf("%d",&n);
	long int *arr = long int[n];
	for(int i=0;i<n;++i)
	scanf("%ld",arr+i);
	
	return 0;
}
