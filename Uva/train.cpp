#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	int *inc = new int[n];
	int *dec = new int[n];
	for(int i=0;i<n;++i)
	scanf("%d",inc+i);
	for(int i=0;i<n;++i)
	scanf("%d",dec+i);
	if(inc[0] == 0)
	printf("NO\n");
	else if(inc[s-1] == 0 && dec[s-1] == 0)
	printf("NO\n");
	else if(inc[s-1] == 0)
	{
		bool found = false;
		for(int i=s;i<n;++i)
		if(inc[i] == 1 && dec[i] == 1)
		found = true;
		if(found)
		printf("YES\n");
		else
		printf("NO\n");		
	}
	else
	printf("YES\n");
	return 0;
}
