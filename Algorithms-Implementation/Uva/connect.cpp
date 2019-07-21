#include <bits/stdc++.h>

using namespace std;

int root(int *parent,int node)
{
	if(parent[node] == node)
	return node;
	return root(parent,parent[node]);
}

void Union(int u,int v,int *parent,int *sum)
{
	int uroot = root(parent,u);
	int vroot = root(parent,v);
	if(vroot != uroot)    //cycle condition
	{
		if(sum[uroot] < sum[vroot])
		{
			parent[vroot] = uroot;
			sum[uroot] += sum[vroot];
		}
		else
		{
			parent[uroot] = vroot;
			sum[vroot] += sum[uroot];
		}
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char node;
		int n,count=0;	
		scanf(" %c",&node);
		n = node - 'A';
		n++;
		int *parent = new int[n];
		int *sum = new int[n];
		for(int i=0;i<n;++i)
		{
			parent[i] = i;
			sum[i] = 1;
		}
		char line[4],u,v;
		u = getchar();
		while(fgets(line,sizeof line,stdin) != NULL)
		{
			if(line[0] == '\n')
			break;	
			u = line[0],v = line[1];
			Union(u-'A',v-'A',parent,sum);
		}
		bool *visited = new bool[n];
		memset(visited,false,sizeof(bool)*n);
		for(int i=0;i<n;++i)
		{
			int comp = root(parent,i);
			if(visited[comp] == false)
			{
				visited[comp] = true;
				count++;
			}
		}
		printf("%d\n",count);
		if(q!=0)
		printf("\n");
	}
	return 0;
}
