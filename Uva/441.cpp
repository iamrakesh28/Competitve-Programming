#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;

void print(vi &ans)
{
	for(int i=0;i<ans.size()-1;++i)
	cout<<ans[i]<<" ";
	cout<<*(ans.end()-1);
	printf("\n");
}
void lotto(vi &S,int k,int index,vi &ans)
{
	if(ans.size() == k)
	{
		print(ans);
		return;
	}
	for(int i=index;i<S.size();++i)
	{
		ans.push_back(S[i]);
		//cout<<i<<" ";
		lotto(S,k,i+1,ans);
		ans.erase(ans.end()-1);
	}
	return ;
}
int main()
{
	int k,i=0;
	while(scanf("%d",&k) != EOF && k != 0)
	{
		if(i++)
		putchar('\n');
		vi S(k);
		for(int i=0;i<k;++i)
		cin>>S[i];
		vi ans;
		lotto(S,6,0,ans);
	}
	return 0;
}
