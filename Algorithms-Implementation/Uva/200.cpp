#include <bits/stdc++.h>

using namespace std;

int alpha[26],id=0;
list <int> *adj;
bool *visited;
void addEdge(int u,int v)
{
	adj[u].push_back(v);
}
char value(int ind)
{
	for(int i=0;i<26;++i)
	if(alpha[i] == ind)
	return (char)(i+'A');
}
void DFS(int u,stack <int> &p)
{
	visited[u] = true;
	for(auto it = adj[u].begin();it!=adj[u].end();++it)
	{
		if(visited[*it] == false)
		DFS(*it,p);
	}
	p.push(u);
}
void topo()
{
	stack <int> p;
	for(int i=0;i<id;++i)
	{
		if(visited[i] == false)
		DFS(i,p);
	}
	//cout<<p.top();
	while(!p.empty())
	{
		int t = p.top();
		cout<<value(t);
		p.pop();
	}
	cout<<endl;
}
int main()
{
	char line[100];
	adj = new list<int>[26];
	memset(alpha,-1,sizeof(int)*26);
	while(scanf("%s",line) != EOF && line[0] != '#')
	{
		char *pt = line;
		int prev = -1;	
		while(*pt != '\0')
		{
			if(alpha[*pt - 'A'] == -1)
			alpha[*pt - 'A'] = id++;
			if(prev != -1)
			addEdge(prev,alpha[*pt - 'A']);
			prev = alpha[*pt - 'A'];
			//cout<<alpha[*pt-'A']<<" "<<id<<endl;
			pt++;		
		}
	}
	visited = new bool[id];
	memset(visited,false,sizeof(bool)*id);
	topo();
	delete [] visited,adj;
	return 0;
}
