#include <bits/stdc++.h>
using namespace std;

long int indx(vector <long int> &vect,long int num,long int last)
{
	for(long int i=last;i<vect.size();++i)
	{
		if(vect[i]>num)
		{
			return i;
		}
	}
	return 0;
}

int main()
{
	int q;
	scanf("%d",&q);
	int n;
	long int h,min,num=INT_MIN;
	double last,val;
	while(q--)
	{
		vector <long int> vect;
		vector <long int> sum;
		scanf("%d%ld",&n,&h);
		last=1;
		for(int i=0;i<n;++i)
		{
			cin>>val;
			vect.push_back(val);
			if(num<val)
			num=val;
			//sum[i]=sum[i-1]+vect[i];
		}
		sort(vect.begin(),vect.end());
		sum.push_back(vect[0]);
		for(int i=1;i<n;++i)
		{
			sum.push_back(sum[i-1]+vect[i]);
		}
		//min=vect[n-1];
		for(long int i=1;i<=vect[0];++i)
		{
			val=(double)(sum[n-1])/i;
			if(val<=h)
			{
				min=i;
				goto lb;
			}
		}
		for(long int i=vect[0]+1;i<=num;++i)
		{
			last=indx(vect,i,last);
			val=last+(double)(sum[n-1]-sum[last-1])/i;
			if(val<=h)
			{
				min=i;
				break;
			}
		}
		lb:;
		printf("%ld\n",min);
	
	}
	return 0;
}
