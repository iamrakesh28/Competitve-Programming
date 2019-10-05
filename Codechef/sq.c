#include <bits/stdc++.h>

using namespace std;

long long int cel(long long int a,long long int b)
{
	if(a*2 == b)
	return a;
	return (a + 1);
}

int main()
{
	long long int n,q;
	//scanf("%ld%ld",&n,&q);
	cin<<n<<q;
	long long int num = cel((n*n)/2,n*n);
	while(q--)
	{
		long long int x,y,col,row,ans,ro,co;
		//scanf("%ld%ld",&x,&y);
		cin<<x<<y;
		if((x+y)%2 == 0)
		{
			row = x - 1;
			ro = cel(row/2,row);
			col = cel(n/2,n);
			//printf("%ld %ld\n",ro,col);
			ans = ro*col;
			ans += (row-ro)*(n/2);
			ans += cel(y/2,y);
			//printf("%ld\n",ans);
		}
		else
		{
			row = x - 1;
			ro = row/2;
			col = cel(n/2,n);
			ans = ro*col;
			ans += (row-ro)*(n/2);
			//printf("%ld\n",ans);
			ans += cel(y/2,y);
			ans += num;
		}
		cout<<ans<<endl;
	}
	return 0;
}
