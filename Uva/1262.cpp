#include <bits/stdc++.h>

using namespace std;

bool mat2[5][26];
char mat1[5][7];

set <string> p;
bool found(vector <int> &seq)
{
	for(int i=0;i<5;++i)
	{
		if(mat2[i][mat1[i][seq[i]] - 'A'] == false)
		return false;
	}
	string a = "";
	for(int i=0;i<seq.size();++i)
	a += mat1[i][seq[i]];
	if(p.find(a) == p.end())
	{
		p.insert(a);
		return true;
	}
	return false;
}
int cnt;
bool password(int k,int col,vector <int> &seq)
{
	if(col == 5)
	{
		if(found(seq))	
		cnt++;
		if(cnt == k)		
		{
			for(int i=0;i<seq.size();++i)
			cout<<mat1[i][seq[i]];
			printf("\n");
			return true;
		} 
		return false;
	}
	for(int i=0;i<6;++i)
	{
		seq.push_back(i);
		if(password(k,col+1,seq))
		return true;
		seq.erase(seq.end()-1);
	}
	return false;
		
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int k;
		char ch;
		cnt = 0;
		scanf("%d",&k);
		for(int i=0;i<6;++i)
		{
			for(int j=0;j<5;++j)
			{
				scanf(" %c",&ch);
				mat1[j][i] = ch;
			}
		}
		for(int i=0;i<5;++i)
		{
			sort(mat1[i],mat1[i]+6);
			memset(mat2[i],false,sizeof(bool)*26);
		}
		for(int i=0;i<6;++i)
		{
			for(int j=0;j<5;++j)
			{
				scanf(" %c",&ch);
				mat2[j][ch - 'A'] = true;
			}
		}
		vector <int> seq;
		if(password(k,0,seq) == false)
		cout<<"NO\n";
		p.clear();
	}
	return 0;
}
