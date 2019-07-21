#include <bits/stdc++.h>

using namespace std;

int alpha[26],id;
list <int> *adj;
int *indegree;

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	indegree[v]++;
}

char value(int ind)
{
	for(int i=0;i<26;++i)
	if(alpha[i] == ind)
	return (char)(i+'a');
}
void topological(bool *visited,vector<int> &res)
{
	bool flag = false;
	for(int i=0;i<id;++i)	
	{
		if(indegree[i] == 0 && visited[i] == false)
		{
			visited[i] = true;
			for(auto it = adj[i].begin();it != adj[i].end();++it)
			indegree[*it]--;
			res.push_back(i);
			topological(visited,res);
			res.erase(res.end()-1);
			visited[i] = false;
			for(auto it = adj[i].begin();it != adj[i].end();++it)
			indegree[*it]++;
			flag = true;
		}

	}
	if(flag == false)
	{
		for(int i=0;i<res.size();++i)
		cout<<value(res[i]);
		cout<<endl;
	}
}
int main()
{
	char line1[200],line2[200],ch;
	int line = 0;
	while(scanf("%[^\n]s",line1) != EOF && (ch = getchar()) && scanf("%[^\n]s",line2) != EOF && (ch = getchar()))
	{
		if(line)
		cout<<endl;
		line++;
		int len = strlen(line1);
		memset(alpha,-1,sizeof(int)*26);
		vector<int> res;
		id = 0;
		for(int i=0;i<len;++i)
		{
			if(line1[i] == ' ')
			continue;
			int v = alpha[line1[i] - 'a'];
			if(v == -1)
			alpha[line1[i] - 'a'] = id++;
		}
		adj = new list<int>[id];
		indegree = new int[id];
		len = strlen(line2);
		memset(indegree,0,sizeof(int)*id);
		int u=-1,v;
		for(int i=0;i<len;++i)
		{
			if(line2[i] == ' ')
			continue;
			if(u == -1)
			{		
				u = alpha[line2[i]-'a'];
				continue;
			}
			v = alpha[line2[i]-'a'];
			//cout<<value(u)<<" "<<value(v)<<endl;
			//if(u != v)
			addEdge(u,v);
			u = -1;
		}
		bool *visited = new bool[id];
		memset(visited,false,sizeof(bool)*id);
		topological(visited,res);
		//cout<<endl;
		delete [] adj,indegree,visited;
	}	
	return 0;
}
