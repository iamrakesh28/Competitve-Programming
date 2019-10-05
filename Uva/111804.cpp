#include <bits/stdc++.h>

using namespace std;

struct Player{
	int att,def;
	string name;
};

bool compare(Player &a, Player &b)
{
	return (a.name).compare(b.name) < 0;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		vector <Player> player(10);
		int def = 0,cur_def,cur_att,maxatt=0,maxdef=0;
		for(int i=0;i<10;++i)
		{
			cin>>player[i].name>>player[i].att>>player[i].def;
			def += player[i].def;
		}
		sort(player.begin(),player.end(),compare);
		int mask ;
		for(int a=0;a<6;++a)
		{
			for(int b = a+1;b<7;++b)
			{
				for(int c = b+1;c<8;++c)
				{
					for(int d = c+1;d<9;++d)
					{
						for(int e = d+1;e<10;++e)
						{
							cur_att = player[a].att + player[b].att + player[c].att + player[d].att + player[e].att;
							cur_def = def - (player[a].def + player[b].def + player[c].def + player[d].def + player[e].def);
							if(cur_att > maxatt)
							{
								maxatt = cur_att;
								maxdef = cur_def;
								mask = 0;
								mask |= (1 << a);
								mask |= (1 << b);
								mask |= (1 << c);
								mask |= (1 << d);
								mask |= (1 << e);
							}
							else if(cur_att == maxatt && cur_def > maxdef)
							{
								maxdef = cur_def;
								mask = 0;
								mask |= (1 << a);
								mask |= (1 << b);
								mask |= (1 << c);
								mask |= (1 << d);
								mask |= (1 << e);
							}
						}
					}
				}
			}
		}
		int cnt=0;
		printf("Case %d:\n(",i);
		for(int j=0;j<10;++j)
		if((mask >> j)%2)
		{
			cout<<player[j].name;
			if(cnt != 4)
			printf(", ");
			cnt++;
		}
		printf(")\n(");
		for(int j=0,cnt=0;j<10;++j)
		if((mask >> j)%2 == 0)
		{
			cout<<player[j].name;
			if(cnt != 4)
			printf(", ");
			cnt++;
		}
		printf(")\n");
	}
	return 0;
}
