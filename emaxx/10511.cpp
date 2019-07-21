#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;
list <int> adj[80002];
string fred[80002];
int capacity[8000][8000];
int main() {
	
	int t;
	char line[128], c;
	scanf("%d", &t);
	c = getchar_unlocked();
	c = getchar_unlocked();
	while (t--) {
		
		string s = "", party, name;
		int cnt = 2, s = 0, t = 1;
		mp.clear();
		while (fgets(line, sizeof line, stdin) != NULL && line[0] != '\n') {
			int i = 0;
			for (char *p = line; *p != '\0'; ++p, ++i) {
				if (*p == ' ') {
					if (i == 0) {
						name = s;
						fred[cnt] = name;
						mp[name] = cnt++;
					}
					else if (i == 1) {
						party = s;
						fred[cnt] = party;
						mp[party] = cnt++;
						int u = mp.at(name), v = cnt - 1;
						adj[u].push_back(v);
						adj[v].push_back(u);
						capacity[u][v] = 1;
						adj[v].push_back(t);
						adj[t].push_back(v);
						capacity[v][t] = 1;
					}
					else {
						fred[cnt] = s;
						mp[s] = cnt++;
						int u = mp.at(name), v = cnt - 1;
						adj[u].push_back(v);
						adj[v].push_back(u);
						capacity[v][u] = 1;
						adj[s].push_back(v);
						adj[v].push_back(s);
						capacity[s][v] = 1;
					}
					s = "";
					i++;
					continue;
				}
				s += *p;
			}
		}
	}
	return 0;
}
