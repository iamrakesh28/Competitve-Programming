#include <bits/stdc++.h>

typedef unsigned long int ul;

using namespace std;

struct Candies{
	ul ai,bi,m;
	bool operator<(const Candies& t) const
    	{
		ul cost1 = this->bi*(this->ai-this->m);
		ul cost2 = t.bi*(t.ai-t.m);
		if(cost1 < cost2)
		return true;
		else if(cost2 < cost1)
		return false;
        	return (this->m < t.m); 
    	} 
};
int main()
{
	set < Candies > min;
	int n;
	scanf("%d",&n);	
	for(int i=0;i<n;++i)
	{
		Candies a;
		scanf("%lu",&a.ai);
		a.bi = a.ai;
		a.m = 0;
		min.insert(a);
	}
	for (auto it = min.begin(); it != min.end(); it++) 
    	{        
		Candies t = *it;
        	cout << t.bi*(t.ai-t.m)<<" "<<t.m<<endl;  
    	}
	//Candies t = --(*min.end());
        //cout << t.bi*(t.ai-t.m)<<" "<<t.m<<endl; 
	return 0;
}
