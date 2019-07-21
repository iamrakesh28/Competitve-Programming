#include <bits/stdc++.h>
using namespace std;

int main()
{
	char ch;
	vector <int> arr;
	int num=0;
	while(ch=getchar()!='\n')
	{
		if(ch==' ')
		{
			arr.push_back(num);
			num=0;
		}
		else
		{
			num = 10*num+ ch - '0';
		}
	}	
	arr.push_back(num);
	sort(arr.begin(),arr.end());
	num = arr[arr.size()/2-1];
	arr[arr.size()/2-1]=arr[arr.size()/2 ];
	arr[arr.size()/2]=num;
	for(int i=0;i<arr.size();++i)
	{
		printf("%d ",arr[i]);
	}	
}

