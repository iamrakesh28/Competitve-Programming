#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool arr[20];
	for(int i=2;i<20;++i)
	arr[i] = true;
	for(int i=2;i*i<20;++i)
	{
		if(arr[i] == true)
		for(int j=2*i;j<20;j+=i)
		arr[j] = false;
	}
	for(int i=2;i<20;++i)
	if(arr[i] == true)
	cout<<i<<" ";
	return 0;
}
