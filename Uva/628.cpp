#include <bits/stdc++.h>

using namespace std;

vector <string> dict;

void password(string &rule,int pos,vector <int> &pass)
{
	if(pos == rule.size())
	{
		for(int i=0;i<rule.size();++i)
		{
			if(rule[i] == '#')
			cout<<dict[pass[i]];
			else
			cout<<pass[i];
		}
		printf("\n");
		return;
	}
	if(rule[pos] == '#')
	for(int i=0;i<dict.size();++i)
	{
		pass[pos] = i;
		password(rule,pos+1,pass);
		pass.erase(pass.end()-1);
	}
	else
	for(int i=0;i<10;++i)
	{
		pass[pos] = i;
		password(rule,pos+1,pass);
		pass.erase(pass.end()-1);
	}
	return;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int m;
		dict.resize(n);
		for(int i=0;i<n;++i)
		cin>>dict[i];
		scanf("%d",&m);
		string rule;
		printf("--\n");
		for(int i=0;i<m;++i)
		{
			cin>>rule;
			vector <int> pass(rule.size());
			password(rule,0,pass);
		}
		dict.clear();
	}
	return 0;
}
