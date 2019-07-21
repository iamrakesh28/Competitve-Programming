#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<=2)
	cout<<"No";
	else
	{
		cout<<"Yes"<<endl;
		if(n%2)
		{
			printf("%d ",n/2+1);
			for(int i=1;i<=n;++i)
			{
				if(i%2)
				printf("%d ",i);
			}
			printf("\n%d ",n/2);
			for(int i=1;i<=n;++i)
			{
				if(i%2 == 0)
				printf("%d ",i);
			}
		}
		else
		{
			int num = n/2;
			if(num%2 == 0)
			printf("%d ",num);
			else
			printf("%d ",num+1);
			for(int i=1;i<=n/2;++i)
			{
				if(i%2)
				printf("%d %d ",i,n-i+1);
			}
			if(num%2 == 0)
			printf("\n%d ",num);
			else
			printf("\n%d ",num-1);
			for(int i=1;i<=n/2;++i)
			{
				if(i%2 == 0)
				printf("%d %d ",i,n-i+1);
			}
		}
	}
	cout<<endl;
	return 0;
}
