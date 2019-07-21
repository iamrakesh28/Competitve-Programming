#include <bits/stdc++.h>

typedef long int ul;

using namespace std;

ul *ai,*bi;
struct Candies{
	ul m;
	int index;
	bool operator<(const Candies& t) const
    	{
		int i = this->index;
		ul cost1 = bi[i]*(ai[i]-this->m);
		ul cost2 = bi[t.index]*(ai[t.index]-t.m);
		if(cost1 == cost2)
		{
			if(this->m == t.m)
			return this->index < t.index;
			return this->m > t.m; 
		}
		return cost1 < cost2;
    	} 
};
bool compare(int &a,int &b)
{
	return (bi[a] > bi[b]);
}

ul minimum(int i,int j,ul em,ul sum)
{
	ul mina = max(bi[i]*(ai[i]-em),bi[j]*(ai[j]-sum+em));
	ul minb = max(bi[i]*(ai[i]-em-1),bi[j]*(ai[j]-sum+em+1));
	if(mina < minb)
	return em;
	return em+1;
}
ul solve(set <Candies> &min)
{
	set <Candies> :: iterator begin,end;
	begin = min.begin();
	end = min.end();
	end--;
	Candies a;
	while(begin != end)
	{
		ul sm = (*begin).m;
		ul em = (*end).m;
		ul sum = sm + em;
		int j = (*begin).index,i = (*end).index;
		//cout<<i<<" "<<j<<endl;
		ul org = bi[i]*(ai[i]-em);
		if(sm)
		{
			em = (bi[i]*ai[i] - bi[j]*ai[j] + sum*bi[j])/(bi[i]+bi[j]);
			em = minimum(i,j,em,sum);
			if(org > bi[i]*(ai[i]-em) && org > bi[j]*(ai[j]-sum+em))
			{
				//cout<<em<<endl;
				a.m = em;
				a.index = (*end).index;
				min.erase(end);
				min.insert(a);
				a.m = sum-em;
				a.index = (*begin).index;
				min.erase(begin);
				min.insert(a);
				begin = min.begin();
				end = min.end();
				end--;
			}
			else
			begin++;
		}
		else
		begin++;
	}
	end = min.end();
	end--;
	int i = (*end).index;
	ul m = (*end).m;
	//cout<<m<<" "<<i<<" "<<endl;
	ul c = bi[i]*(ai[i]-m);
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
	int *arr = new int[n];
	for(int i=0;i<n;++i)
	{
		scanf("%ld",ai+i);
		sum_a += ai[i];
	}
	if(sum_a <= m)
	{
		//cout<<m<<endl;
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;++i)
	{
		scanf("%ld",bi+i);
		arr[i] = i;
	}
	sort(arr,arr+n,compare);
	for(int i = 0;i<n;++i)
	{
		Candies a;
		if(m >= ai[arr[i]])
		{
			m -= ai[arr[i]];
			a.m = ai[arr[i]];
			a.index = arr[i];
		}
		else
		{
			a.m = m;
			a.index = arr[i];
			m = 0;
		}
		min.insert(a);
	}
	/*for (auto it = min.begin(); it != min.end(); it++) 
    	{        
		Candies t = *it;
		int i = t.index;
        	cout << bi[i]*(ai[i] - t.m)<<" "<<endl;  
    	}*/
	//Candies t = --(*min.end());
        //cout << t.bi*(t.ai-t.m)<<" "<<t.m<<endl; 
	ul c = solve(min);
	printf("%ld\n",c);
	delete[] ai,bi;
	return 0;
}

