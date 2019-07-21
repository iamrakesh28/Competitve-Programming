#include <bits/stdc++.h>

#define pb(x) push_back(x) 
using namespace std;

vector <string> table = {"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY","YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"};

bool compare(string &input,int pos,vector <int> &bad,int cur)
{
	for(int i=0;i<7;++i)
	{
		if(input[i] == 'N' && bad[i] < cur)
		continue;
		if(input[i] != table[pos][i])
		return false;
	}
	return true;
}
void possiblity(string &input,vector <vector <int>> &poss,int cur,vector <int> &bad)
{
	for(int i=9;i>=0;i--)
	{
		if(compare(input,i,bad,cur))
		poss[cur].pb(i);
	}
}

bool backtrack(int pos,vector <vector <int>> &poss,int n,int cur)
{
	if(pos == n)
	return true;
	for(int i=0;i<poss[pos].size();++i)
	if(cur == poss[pos][i])
	return backtrack(pos+1,poss,n,cur-1);
	return false;
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF && n)
	{
		vector <vector <int>>poss(n);
		vector <string> input(n);
		vector <int> bad(7,-1);
		for(int i=0;i<n;++i)
		cin>>input[i];
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<7;++j)
			if(input[i][j] == 'Y')
			bad[j] = i;
		}
		for(int i=0;i<n;++i)
		possiblity(input[i],poss,i,bad);
		bool found = false;
		for(int i=poss[0].size()-1;i>=0;i--)
		{
			if(backtrack(1,poss,n,poss[0][i]-1))
			{
				found = true;
				break;
			}
		}
		if(found)
		printf("MATCH\n");
		else
		printf("MISMATCH\n");
	}
	return 0;
}
