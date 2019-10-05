#include <bits/stdc++.h>

using namespace std;

#define RE 1000000000

void corner(int x,int y)
{
	printf("Q %d %d\n",RE,y);
	fflush(stdout);
	int dist,xu,yu;
	scanf("%d",&dist);
	xu = RE-dist;
	printf("Q %d %d\n",x,RE);
	fflush(stdout);
	scanf("%d",&dist);
	yu = RE-dist;
	printf("A %d %d %d %d\n",x,y,xu,yu);
	fflush(stdout);
	scanf("%d",&dist);
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y,x0=0,distl,distr;
		printf("Q %d %d\n",0,0);
		fflush(stdout);
		scanf("%d",&distl);
		if(distl == 0)
		{
			corner(0,0);
			continue;
		}
		x = RE;
		printf("Q %d %d\n",x,0);
		fflush(stdout);
		scanf("%d",&distr);
		if(distl < distr)
		x = x-(distr-distl);
		else if(distl > distr)
		x0 = distl-distr;
		long int mid = ((long int)x + (long int)x0)/2;
		printf("Q %ld %d\n",mid,0);
		fflush(stdout);
		scanf("%d",&y);
		x = distl-y;
		corner(x,y);
	}
	return 0;
}
