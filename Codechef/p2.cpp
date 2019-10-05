#include <bits/stdc++.h>

using namespace std;

bool compare(char *a, char *b)
{
	if(strcmp(a,b) < 0)
	return true;
	return false;
}
bool found(char **M,char *a,int m)
{
	int begin =0,end = m-1,middle;
	while(begin <= end)
	{
		middle = (begin + end)/2;
		int cmp = strcmp(M[middle],a);
		if(cmp == 0)
		{
			return true;
		}
		else if(cmp < 0)
		begin = middle+1;
		else
		end = middle-1;
		
	} 
	return false;
}

int choose(int *diff,int p,int *index,bool *mark)
{
	int min = INT_MAX,diff;
	for(int i=0;i<p;++i)
	{
		if(diff[i] < min && mark[i] == false)
		{
			min = diff[i];
			*index = i;
		}
	}
	return min;

}
int cost(int **bit,int p,char *test)
{
	int c=0;
	for(int i=0;i<p;++i)
	{
		if(test[i] - '0')
		{
			c += bit[0][p-i-1];
		} 
		else
		{
			c += bit[1][p-i-1];
		}	
	}
	return cost;
}

void recur(char **M,int *diff,int p,int m,char *test,int **bit)
{
	int index;
	//for(int i=0;i<p;++i)
	{
		int min = choose(diff,p,&index,mark);
		mark[index] = true;
		if(test[index] - '0')
		test[index] = '0';
		else
		test[index] = '1';
		if(found(M,test,m)== false)
		int v = cost(bit,p,test);
		if(v == INT_MAX)
		return ;
		return recur(M,diff,p,m,test,bit);
		mark[index] = false;
		if(test[index] - '0')
		test[index] = '1';
		else
		test[index] = '0';	
	}
}

int optim(char **M, int **bit, int p,int m)
{
	int c=0;
	char *test = new char[p];
	bool *mark = new bool[p];
	for(int i=0;i<p;++i)
	{
		if(bit[0][p-i-1] > bit[1][p-i-1])
		{
			c += bit[1][p-i-1];
			test[i] = '0';
		} 
		else
		{
			test[i] = '1';
			mark[i] = true;
			c += bit[0][p-i-1];
		}	
	}
	if(found(M,test,m)== false)
	return c;	
	int *diff = new int[p];
	for(int i=0;i<p;++i)
	diff[i] = abs(bit[0][i]-bit[1][i]);
	
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		int **bit = new int*[2];
		bit[0] = new int [p];
		bit[1] = new int [p];
		memset(bit[0],0,sizeof(int)*p);
		memset(bit[1],0,sizeof(int)*p);
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<p;++k)
			{
				char c;
				scanf(" %c",&c);
				bit[c - '0'][k]++;
			}
		}
		char **M = new char*[m];
		for(int j=0;j<m;++j)
		{
			M[j] = new char[p];
			for(int k=0;k<p;++k)
			{
				scanf(" %c",M[j]+k);
			}
		}
		sort(M,M+m,compare);
		printf("Case #%d: %d\n",i,optim(M,bit,p,m));
	}
	return 0;
}
