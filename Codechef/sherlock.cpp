#include <bits/stdc++.h>

using namespace std;

long int search(vector <long int> &m,long int n)
{
	long int dev,min,num;
	min = abs(m[0]-n);
	num = m[0];
	vector <long int> :: iterator it;
	for(it = m.begin();it!=m.end();++it)
	{
		dev = abs(*it-n);
		if(dev < min)
		{
			min = dev;
			num = *it;
		}
	}
	return abs(num-n);
}

int main()
{
	int q;
	scanf("%d",&q);
	vector <long int> m;
	for(int x = 0;x <=30;++x)
	{
		for(int y = 0; y <=30;y++)
		{
			long int a = 1<<x,b = 1<<y;
			if(x!=y)
			{
				m.push_back(a + b);
			}	
		}
	}
	while(q--)
	{
		long int n;
		scanf("%ld",&n);
		printf("%ld\n",search(m,n));
	}
}

