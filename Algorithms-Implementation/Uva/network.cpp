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
		int n,suc=0,unsec=0;	
		scanf("%d",&n);
		int *parent = new int[n];
		int *sum = new int[n];
		for(int i=0;i<n;++i)
		{
			parent[i] = i;
			sum[i] = 1;
		}
		//cout<<n<<endl;
		char line[100],ch;
		ch = getchar();
		while(fgets(line,sizeof line,stdin) != NULL)
		{
			int u,v;
			//cout<<line;
			if(line[0] == '\n')
			break;	
			sscanf(line,"%c%d%d",&ch,&u,&v);
			if(ch == 'c')
			Union(u-1,v-1,parent,sum);
			else
			{
				u = root(parent,u-1);
				v = root(parent,v-1);
				if(u == v)
				suc++;
				else
				unsec++;
			}
		}
		printf("%d,%d\n",suc,unsec);
		if(q!=0)
		printf("\n");
	}
	return 0;
}
