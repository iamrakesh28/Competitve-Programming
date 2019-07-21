#include <bits/stdc++.h>

using namespace std;

bool possible(int num,int denum)
{
	if(num >= 100000 || num < 10000)
	return false;
	int mask = 0,c,r,count=0;
	while(num)
	{
		r = num%10;
		num = num/10;
		if((mask >> r)%2)
		return false;
		mask = mask | (1 << r);
	}
	while(denum)
	{
		r = denum%10;
		denum = denum/10;
		if((mask >> r)%2)
		return false;
		mask = mask | (1 << r);
		count++;
	}
	if(count == 4)
	if((mask >> 0)%2)
	return false;
	return true;
}
int main()
{
	int n,count=0;
	while(scanf("%d",&n) != EOF && n)
	{
		if(count++)
		cout<<"\n";
		int num,cnt=0;
		for(int i=1234;i<50000;++i)
		{
			num = n*i;
			if(possible(num,i))
			{
				cnt = 1;
				printf("%05d / %05d = %d\n", num, i, n);
			}
		}
		if(!cnt)
		printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
