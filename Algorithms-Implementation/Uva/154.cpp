#include <bits/stdc++.h>

using namespace std;

int dust[5][5];
//roygb PGSAN
int city[100][5];
int mapcol(char ch)
{
	switch(ch)
	{
		case 'r': return 0;
		case 'o': return 1;
		case 'y': return 2;
		case 'g': return 3;
		case 'b': return 4;
	}
}
int mapdust(char ch)
{
	switch(ch)
	{
		case 'P': return 0;
		case 'G': return 1;
		case 'S': return 2;
		case 'A': return 3;
		case 'N': return 4;
	}
}//row - color
void parse(int n,char *line)
{
	char *pt = line;
	for(;*pt != '\0';pt++)
	{
		if(*pt == ',')
		continue;
		int col = mapcol(*pt);
		int dus = mapdust(*(pt+2));
		dust[dus][col]++;
		city[n][col] = dus;
		pt = pt + 2;
	}
}
int main()
{
	char line[20];
	line[0] = 'r';		
	while(line[0] != '#')
	{
		int n = 0;
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			dust[i][j] = 0;
		}
		while(scanf("%s",line) && (line[0] != 'e' && line[0] != '#'))
		{
			printf("%s\n",line);
			parse(n++,line);
		}
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			cout<<dust[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
