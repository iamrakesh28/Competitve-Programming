#include <bits/stdc++.h>

typedef long int ul;

using namespace std;

ul *ai,*bi;
struct Candies{
	ul cost;
	int index;
	bool operator<(const Candies& t) const
    	{
		ul cost1 = this->cost;
		ul cost2 = t.cost;
		if(cost1 == cost2)
		{
			if(bi[this->index] == bi[t.index])
			return this->index < t.index;
			return bi[this->index] < bi[t.index];
		}
		return cost1 < cost2; 
    	} 
};

ul solve(set <Candies> &min,ul m)
{
	set <Candies> :: iterator end;
	Candies a;
	while(m)
	{
		end = min.end();
		end--;
		a = *end;
		min.erase(end);
		a.cost = a.cost - bi[a.index];
		m--;
		min.insert(a);
	}
	end = min.end();
	end--;
	ul c = (*end).cost;
	return c;
}
bool isPossible(ul m,ul height,int n)
{
	ul req = 0;
	for(int i=0;i<n;++i)
	{
		if(ai[i]*bi[i] >= height)
		{
			ul c,diff = ai[i]*bi[i] - height;
			c = diff/bi[i];
			if(c*bi[i] != diff)
			req++;
			req += c;
		}
	}
	//cout<<req<<" "<<height<<endl;
	if(req <= m)
	return true;
	return false;
}
ul suitable(ul *cost,ul m,int n,ul height)
{
	ul begin = 0,end = height,middle,prev = m;
	while(begin <= end)
	{
		middle = (begin + end)/2;
		bool poss = isPossible(m,middle,n);
		if(poss == true)
		{
			prev = middle;
			end = middle - 1;
		}
		else
		begin = middle + 1;
		
	}
	ul req = 0;
	for(int i=0;i<n;++i)
	{
		if(ai[i]*bi[i] >= prev)
		{
			ul c,diff = ai[i]*bi[i] - prev;
			c = diff/bi[i];
			if(c*bi[i] != diff)
			c++;
			req += c;
			cost[i] -= bi[i]*c;
		}
	}
	//cout<<req<<endl;
	return m-req;
	
}
int main()
{
	set < Candies > min;
	int n;
	ul m,sum_a = 0,height = 0 ;
	scanf("%d%ld",&n,&m);
	ai = new ul[n];
	bi = new ul[n];	
	ul *cost = new ul[n];
	for(int i=0;i<n;++i)
	{
		scanf("%ld",ai+i);
		sum_a += ai[i];
	}
	if(sum_a <= m)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;++i)
	{
		scanf("%ld",bi+i);
		cost[i] = ai[i]*bi[i];
		height = max(cost[i],height);
	}
	m = suitable(cost,m,n,height);
	//cout<<m<<endl;
	for(int i = 0;i<n;++i)
	{
		Candies a;
		a.index = i;
		a.cost = cost[i];
		min.insert(a); 
	}
	ul c = solve(min,m);
	printf("%ld\n",c);
	delete[] ai,bi,cost;
	return 0;
}

