#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,num=0;
	cin>>n;
	char *a = new char[n+1];
	char *b = new char[n+1];
	scanf("%s%s",a,b);
	for(int i=0;i<n;++i)
	{
		if(a[i] != b[i])
		{
			if(i < n-1 && (a[i+1] != b[i+1]))
			{
				if(a[i] != a[i+1])
				{
					num++;
					a[i] = b[i];
					a[i+1] = b[i+1];
				}
				else
				num++;
			}
			else
			num++;
		}
	}
	cout<<num<<endl;
	return 0;
}
