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
		//cout<<a.cost<<" "<<a.index<<" "<<m<<endl;
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
int main()
{
	set < Candies > min;
	int n;
	ul m,sum_a = 0 ;
	scanf("%d%ld",&n,&m);
	ai = new ul[n];
	bi = new ul[n];	
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
	scanf("%ld",bi+i);
	for(int i = 0;i<n;++i)
	{
		Candies a;
		a.index = i;
		a.cost = bi[i]*ai[i];
		min.insert(a);
		//cout <<a.cost<<" "<<a.index<<endl; 
	}
	/*for(auto it = min.begin(); it != min.end(); it++) 
    	{        
		Candies t = *it;
		int i = t.index;
        	cout <<t.cost<<" "<<i<<endl;  
    	}*/
	ul c = solve(min,m);
	printf("%ld\n",c);
	delete[] ai,bi;
	return 0;
}

