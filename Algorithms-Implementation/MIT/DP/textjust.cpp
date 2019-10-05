#include <bits/stdc++.h>

#define LINE 50
#define INF 1000000

using namespace std;

char word[LINE];
vector <char *> words;
vector <int> length;
int *parent;

int compute_cost(int word_len)
{
	if(word_len > LINE)
	return INF;
	return (int)pow((LINE-word_len),3);
}

int minimum(int a,int b,int i,int j)
{
	if(a < b)
	{
		parent[i] = j;
		return a;
	}
	return b;
}

void justification(int n)
{
	int *cost = new int[n+1];
	int *prefix = new int[n+1];
	memset(cost,INF,sizeof(int)*n);
	cost[n] = 0;
	int i;
	for(i=n-1;i>=0;i--)
	{
		int len=0;
		for(int j=i+1;j<n+1;j++)
		{
			len += length[j-1]+1;
			cost[i] = minimum(compute_cost(len-1) + cost[j],cost[i],i,j);
		}
	}
	i = 0;
	prefix[0] = 0;
	for(int j=1;j<n+1;++j)
	prefix[j] = prefix[j-1] + length[j-1];
	while(parent[i] != i)
	{
		int fill;
		int sum = prefix[parent[i]] - prefix[i];
		int num = parent[i]-i-1;
		if(num == 0)
		fill = 0;
		fill = (LINE - sum)/num;
		int rem = (LINE - sum) - fill*num;
		for(int j = i;j < parent[i];++j)
		{
			printf("%s",words[j]);
			int space = fill;
			if(j != parent[i] - 1)
			while(space--)
			putchar(' ');
			if(j == parent[i]-2 && rem)
			putchar(' ');
		}
		cout<<endl;
		i = parent[i];
	}
	delete [] cost,prefix;
}

int main()
{
	while(scanf("%s",word) != EOF)
	{
		int len = strlen(word);
		char *pt = new char[len+1];
		strcpy(pt,word);
		words.push_back(pt);
		length.push_back(len);
	}
	int n = words.size();
	parent = new int[n+1];
	for(int i=0;i<n+1;++i)
	parent[i] = i;
	justification(n);
	delete [] parent;
	for(int i=0;i<n;++i)
	delete [] words[i];
	return 0;
}
