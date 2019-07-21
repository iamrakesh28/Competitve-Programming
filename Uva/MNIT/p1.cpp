#include <bits/stdc++.h>

using namespace std;


int n;


int main()
{
	scanf("%d",&n);
	map <string,int> m;
	int *arr = new int[n];
	bool *check = new bool[n];
	vector <vector <int>> p(n);
	vector <string> st;
	memset(arr,0,sizeof arr);
	for(int i=0;i<n;++i)
	{
		string c = "";
		for(int j=0;j<n;++j)
		{
			char ch;
			scanf(" %c",&ch);
			c += ch;
		}
		st.push_back(c);
		auto it = m.find(c);
		if(it == m.end())
		{
			m[c] = i;
			arr[i]++;
			p[i].push_back(i);
		}
		else
		{
			arr[m.at(c)]++;
			p[m.at(c)].push_back(i);
		}
		
	}
	int cnt = 0;
	for(int i=0;i<n;++i)
	{
		if(arr[i])
		{
			bool sts = true;
			memset(check,false,sizeof(bool)*n);
			for(auto it=p[i].begin();it!=p[i].end();++it)
			check[*it] = true;
			string s = st[i];
			for(int j=0;j<n;++j)
			{
				if(check[j] == false && s[j] == 'T')
				sts = false;
				//arr[i]--;
				if(check[j] == true && s[j] == 'F')
				arr[i]--;
			}
			if(sts)
			cnt = max(cnt,arr[i]);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
