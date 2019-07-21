#include <bits/stdc++.h>

using namespace std;

double dist[55],price[55],d,cap,mpg,init;

double minCost(int station,double capacity,int n)
{
	if(station == n)
	return 0;
	double fuel = (dist[station+1] - dist[station])/mpg;
	double fcost,best;
	if(capacity > cap/2.0 && fuel <= capacity)
	return minCost(station+1,capacity - fuel,n);
	fcost = (cap - capacity)*price[station];
	if(fuel > capacity)
	return round(200 + fcost + minCost(station+1,cap - fuel,n));
	best = round(200 + fcost + minCost(station+1,cap - fuel,n));
	best = min(best,minCost(station+1,capacity - fuel,n));
	return best;
}
int main()
{
	int i=0;
	while(scanf("%lf",&d) != EOF && d >= 0)
	{
		int n;
		scanf("%lf%lf%lf%d",&cap,&mpg,&init,&n);
		for(int i=0;i<n;++i)
		scanf("%lf%lf",&dist[i],&price[i]);
		dist[n] = d;
		double fuel = dist[0]/mpg;
		double ans = init + minCost(0,cap-fuel,n)/100;
		printf("Data Set #%d\n",++i);
		printf("minimum cost = $%0.2lf\n",ans);
	}
	return 0;
}
