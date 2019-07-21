#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,t,x,val=0;
	scanf("%d",&n);
	queue <int> q;
	stack <int> p;
	for(int i=0;i<n;++i)
	{
		int c;
		scanf("%d",&c);
		q.push(c);
	}
	scanf("%d%d",&t,&x);
	char s[10];
	while(t--)
	{
		scanf("%s",s);
		if(val == x)
		{
			printf("%d\n",p.size());
			return 0;
		}
		if(s[0] == 'H')
		{
			int u = q.front();
			q.pop();
			p.push(u);
			val += u;
		}
		else
		{
			int u = p.top();
			p.pop();
			val -= u;
		}
		if(val == x)
		{
			printf("%d\n",p.size());
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
