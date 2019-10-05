#include <bits/stdc++.h>

using namespace std;

long int minm(long int a,long int b)
{
	return a<b?a:b;
}

int main()
{
	long int n;
	cin>>n;
	long int ch;
	vector <long int> a,b;
	for(long int i=0;i<n;i++)
	{
		//scanf("%ld",&ch);
		cin>>ch;
		a.push_back(ch);
	}
	for(long int i=0;i<n;i++)
	{
		//scanf("%ld",&ch);
		cin>>ch;
		b.push_back(ch);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long int az=n-1,bz=n-1,count=1;
	long int suma=0,sumb=0;
	while(az >=0 || bz >=0)
	{
		if(count%2)
		{
			if(az >=0 && bz >=0)
			{
				if(a[az] >= b[bz])
				{
					suma += a[az];
					az--;
				}
				else
				bz--;
			}
			else
			{
				if(az >= 0)
				{
					suma += a[az];
					az--;
				}
				else
				bz--;
			}
		}
		else
		{
			if(az >=0 && bz >=0)
			{
				if(a[az] <= b[bz])
				{
					sumb += b[bz];
					bz--;
				}
				else
				az--;
			}
			else
			{
				if(bz >= 0)
				{
					sumb += b[bz];
					bz--;
				}
				else
				az--;	
			}
		}
		count++;
	}
	cout<<suma-sumb<<endl;
	return 0;
}
