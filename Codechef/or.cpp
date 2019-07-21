#include <bits/stdc++.h>

using namespace std;

struct bin{
	int cost = 30;
	bool exist = false;
};


int calculate(bin *arr,int k,int n)
{
	int limit = 1 << 12,num;
	for(int i=0;i<limit;++i)
	{
		for(int j=i+1;j<limit;++j)
		{
			if(arr[i].exist == true && arr[j].exist == true)
			{
				num = (i+1)|(j+1);
				//printf("%d ",arr[num-1].cost);
				if(arr[num-1].cost > arr[i].cost+arr[j].cost)
				{
					arr[num-1].cost = arr[i].cost+arr[j].cost;
					//printf("%d ",arr[(i+1)|(j+1)-1].cost);
					if(arr[num-1].cost <= k)
					arr[num-1].exist = true;
				}
			}
		}
	}
	int count = 0;
	for(int i=0;i<limit;++i)
	{
		if(arr[i].exist==true)
		count++;
	}
	return count;
}

int main()
{
	int n,k,num,limit = 1 << 12;
	scanf("%d%d",&n,&k);
	bin *arr = new bin[limit];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&num);
		arr[num-1].cost=1;
		arr[num-1].exist=true;
	}
	int result=calculate(arr,k,n);
	printf("%d\n",result);
	return 0;
}
