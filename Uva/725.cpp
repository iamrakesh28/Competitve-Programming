#include <bits/stdc++.h>

using namespace std;

typedef vector <pair<int,int>> vp;
vp *number;
int num[5];
bool digitdeno[10];
bool digitnum[10];

int convert()
{
	int cnt = 0;
	for(int i=0;i<5;++i)
	cnt = cnt*10 + num[i];
}
bool dist(int num)
{
	int cnt = 0;
	for(int i=0;i<10;++i)
	digitnum[i] = digitdeno[i];
	while(num)
	{
		digitnum[num%10] = true;
		num = num/10;
	}
	for(int i=0;i<10;++i)
	if(digitnum[i] == true)
	cnt++;
	memset(digitnum,false,sizeof(bool)*10);
	if(cnt == 10)
	return true;
	return false;
}
void check(int n)
{
	int cnt = convert();
	int num = cnt*n;
	if(dist(num) && num <= 99999)
	number[n-2].push_back(make_pair(num,cnt));
	return;
}
void perm(int index,int n)
{
	if(index == 5)
	{
		check(n);
		return;
	}
	for(int i=0;i<10;++i)
	{
		if(digitdeno[i] == false)
		{
			digitdeno[i] = true;
			num[index] = i;
			perm(index+1,n);
			digitdeno[i] = false;
		}
	}
}
int main()
{
	int n;
	number = new vp[80];
	for(int i=2;i<80;++i)
	{
		memset(digitdeno,false,sizeof(bool)*10);
		memset(digitnum,false,sizeof(bool)*10);
		perm(0,i);
	}
	int i=0;
	while(scanf("%d",&n) != EOF && n)
	{
		if(i++)
		printf("\n");
		if(number[n-2].size() == 0)
		printf("There are no solutions for %d.\n",n);
		else
		{
			for(auto it = number[n-2].begin();it != number[n-2].end();++it)
			{
				int a = (*it).first;
				int b = (*it).second;
				printf("%d / ",a);
				if(b <= 9999)
				putchar('0');	
				printf("%d = %d\n",b,n);
			}
		}
	}
	return 0;
}
