#include <bits/stdc++.h>

using namespace std;

struct Problem{
	int subtask;
	int user;
};

struct Contest{
	int i,n;
};
 
bool compare(Problem a, Problem b)
{
	return (a.subtask < b.subtask);
}

bool comparator(Contest a, Contest b)
{
	if(a.n < b.n)
	return true;
	else if(a.n == b.n)
		return (a.i < b.i);
	return false;
}

int condition(Problem *prob,int s)
{
	int count = 0;
	for(int i=0;i<s-1;++i)
	{
		if(prob[i].user > prob[i+1].user)
		count++;
	}
	return count;
}

int main()
{
	int p,s;
	scanf("%d%d",&p,&s);
	Problem *prob = new Problem[s];
	Contest *contest = new Contest[p];
	for(int i=0;i<p;++i)
	{
		for(int j=0;j<s;++j)
		scanf("%d",&prob[j].subtask);
		for(int j=0;j<s;++j)
		scanf("%d",&prob[j].user);
		sort(prob,prob+s,compare);
		contest[i].i = i+1;
		contest[i].n = condition(prob,s);
	}
	sort(contest,contest+p,comparator);
	for(int i=0;i<p;++i)
	{
		printf("%d\n",contest[i].i);
	}
	return 0;
}
