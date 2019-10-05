#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	stack <int> p;
	while(t--)
	{
		int i,c;
		scanf("%d",&i);
		if(i == 1)	
		{
			if(p.empty())
			printf("No Food\n");
			else
			{
				printf("%d\n",p.top());
				p.pop();
			}
		}
		else
		{
			scanf("%d",&c);
			p.push(c);
		}
	}
	return 0;
}
