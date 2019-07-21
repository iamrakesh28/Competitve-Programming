#include <bits/stdc++.h>

using namespace std;

bool pos(int *arr,int rem,int n,int i,int k)
{
	//sort(arr+i,arr+n);
	//arr[n-1] += rem;
	for(int j = n-1;j>=i;--j)
	{
		if(rem >= arr[j]-k)
		{
			rem=rem -(arr[j]-k);
		}
		else
		{
			//arr[j] -= rem;
			rem = arr[j]-rem-k;
		}
	}
	if(rem > 0)
	return false;
	return true;
		
}
int bin(int *arr,int n,int max,int i,int k)
{
	int beg =0 ,end = max,middle,rem,rep=0;
	while(beg<=end)
	{
		middle = (beg+end)/2 - k;
		rem = max - middle;
		bool res = pos(arr,rem,n-1,i,k);
		if(middle <= k)
		return k;
		//cout<<res<<endl;
		if(res == false)
		{
			end = middle-1;
		}
		else
		{
			rep = middle;
			beg = middle+1;
		}
	}
	return rep;
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,k,sum=0;
		scanf("%d%d",&n,&k);
		int *arr = new int[n];
		for(int i=0;i<n;++i)
		scanf("%d",arr+i);
		sort(arr,arr+n);
		int i;
		for(i=0;i<n;++i)
		{
			if(arr[i] > k)
			{
				break;
			}
			sum += arr[i];
			//cout<<arr[i]<<" ";
		}
		int res = bin(arr,n,arr[n-1]-k,i,k);
		//cout<<res<<endl;
		sum += res + (n-i)*k;
		printf("%d\n",sum);
	}
	return 0;
}
