#include <bits/stdc++.h>

using namespace std;

int mapp[26],id;
list <int> *adj;
int *indegree;

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	indegree[v]++;
}

void topological(bool *visited)
{
	for(int i=0;i<id;++i)	
	{
		if(indegree[i] == 0 && visited[i] == false)
		{
			visited[i] = true;
			for(auto it = adj[i].begin();it != adj[i].end();++it)
			indegree[*it]--;
			topological(bool *visited);
			visited[i] = false;
			for(auto it = adj[i].begin();it != adj[i].end();++it)
			indegree[*it]++;
		}
	}
}
int main()
{
	char line1[100],line2[100],ch;
	while(scanf("%[^\n]s",line1) != EOF && (ch = getchar()) && scanf("%[^\n]s",line2) != EOF && (ch = getchar()))
	{
		int len = strlen(line1);
		//memset(mapp,-1,size(bool)*26);
		id = 0;
		for(int i=0;i<len;++i)
		{
			if(line1[i] == ' ')
			continue;
			mapp[line1[i] - 'a'] = id++;
		}
		adj = new list<int>[id];
		indegree = new int[id];
		len = strlen(line2);
		memset(indegree,0,sizeof(int)*id);
		for(int i=0;i<len;++i)
		{
			if(line2[i] == ' ')
			continue;
			addEdge(mapp[line2[i]-'a'],mapp[line2[i+2]-'a']);
			i += 3;
		}
		bool *visited = new bool[id];
		memset(visited,false,sizeof(bool)*id);
		delete [] adj,indegree,visited;
	}	
	return 0;
}
