#include <bits/stdc++.h>

using namespace std;

int arr[12];
bool found;

set <string> p;
string convert(int num)
{
	string q = "";
	while(num)
	{
		q = (char)(num%10 + '0') + q;
		num = num/10;
	}
	return q;
}
void SumItUp(int n,int t,int sum,int ind,int mask)
{
	if(sum > t)
	return;
	if(sum == t)
	{
		found = true;
		int temp = 0;
		string q = "";
		for(int i=0;i<n;++i)
		{
			if((mask >> i)%2)
			{
				temp += arr[i];
				q += convert(arr[i]);
				if(temp != t)
				q += '+';
			}
		}
		if(p.find(q) == p.end())
		{
			p.insert(q);
			cout<<q<<"\n";
		}
		return;
	}
	if(ind == n)
	return;
	SumItUp(n,t,sum+arr[ind],ind+1,mask | (1 << ind));
	SumItUp(n,t,sum,ind+1,mask);
}

int main()
{
	int t,n;
	while(scanf("%d%d",&t,&n) != EOF && n)
	{
		found = false;
		for(int i=0;i<n;++i)
		scanf("%d",arr+i);
		printf("Sums of %d:\n",t);
		SumItUp(n,t,0,0,0);
		if(found == false)
		printf("NONE\n");
		p.clear();
	}
	return 0;
}
