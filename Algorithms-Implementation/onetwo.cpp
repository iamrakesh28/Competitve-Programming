#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;	
		scanf("%d",&n);
		int *arr = new int[n];
		int *sum = new int[n+1];
		int left = -1,right = -1;
		sum[0] = 0;
		for(int i=0;i<n;++i)
		{	
			scanf("%d",arr+i);
			if(arr[i] == 1 && left == -1)
			left = i;
			if(arr[i] == 1)
			right = i;
			sum[i+1] = sum[i] + arr[i];
		}
		if(left == -1)
		{
			cout<<n<<endl;
			continue;
		}
		int num;
		if(right+1 > n-left)
		num = sum[right+1] + n-right-1;
		else
		num = sum[n] - sum[left] + left;
		cout<<num<<endl;
		delete [] sum,arr;
	}
	return 0;
}
