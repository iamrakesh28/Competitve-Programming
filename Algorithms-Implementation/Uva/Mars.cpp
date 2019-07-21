#include <bits/stdc++.h>

#define loop(n) for(int i=0;i<n;++i)

using namespace std;

int root(int *parent,int node)
{
	if(parent[node] == node)
	return node;
	return root(parent,parent[node]);
}

bool Union(int *parent,int *size,int u,int v,char *alpha)
{
	int uroot = root(parent,u);	
	int vroot = root(parent,v);
	if(alpha[uroot] == 'a' || alpha[vroot] == 'a')
	{
		if(alpha[uroot] == 'a')
		alpha[uroot] = alpha[vroot];
		else
		alpha[vroot] = alpha[uroot];
	}
	else if(alpha[uroot] != alpha[vroot])
	return false;
	if(size[uroot] < size[vroot])
	{
		parent[vroot] = uroot;
		size[uroot] += size[vroot];
	}
	else
	{	
		parent[uroot] = vroot;
		size[vroot] += size[uroot];
	}
	return true;
}

bool isChar(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
	return true;
	return false;
}

int main()
{
	int m;	
	while(scanf("%d",&m) != EOF)
	{
		int flag=0,mut;
		char *dna = new char[2*m+1];
		char *result = new char[2*m+1];
		int *size = new int[2*m];
		int *parent = new int[2*m];
		char *alpha = new char[2*m+1];
		loop(2*m)
		{
			parent[i] = i;
			size[i] = 1;
			alpha[i] = 'a';
			result[i] = 'b';
		}
		loop(m)
		scanf(" %c",dna+i);
		loop(m)
		{
			scanf(" %c",dna+i+m);
			if(isChar(dna[i+m]) && isChar(dna[i]))
			{
				alpha[i+m] = alpha[i] = dna[i];
				if(dna[i+m] != dna[i])
				flag = 1;
			}
			else if(isChar(dna[i+m]))
			{
				mut = root(parent,dna[i]-'1');
				if(alpha[mut] == dna[i+m] || alpha[mut] == 'a')
				alpha[mut] = dna[i+m];
				else
				flag = 1;
			}
			else if(isChar(dna[i]))
			{
				mut = root(parent,dna[i+m]-'1');
				if(alpha[mut] == dna[i] || alpha[mut] == 'a')
				alpha[mut] = dna[i];
				else
				flag = 1;

			}
			else
			{
				if(Union(parent,size,dna[i+m]-'1',dna[i]-'1',alpha)==false)
				flag = 1;

			}
		}
		if(flag)
		{
			printf("NO\n");
			//if(q!=0)
			putchar('\n');
			continue;
		}
		printf("YES\n");
		loop(2*m)
		{	
			if(isChar(dna[i]) == false)
			{
				mut = root(parent,dna[i]-'1');
				if(alpha[mut] == 'a')
				continue;
				result[dna[i]-'1'] = alpha[mut];
				//cout<<dna[i]-'0'<<" "<<result[dna[i]-'1']<<endl;	
			}
		}
		loop(2*m)
		{
			if(result[i] != 'b')
			{
				cout<<i+1<<" "<<result[i]<<endl;
				//printf("%d %c \n",num+1,result[num]);
			}
		}
		//delete[] dna,size,parent,alpha,result;
		//if(q!=0)
		putchar('\n');
	}
	return 0;
}
