#include <bits/stdc++.h>

using namespace std;

int *par,*size;

int main()
{
	int m=1;
	//while(scanf("%d",&m) != EOF)
	{
		int *dna = new int[2*m];
		for(int i=0;i<2*m;++i)
		{
			scanf("%d",dna+i);
			printf("%d=",dna[i]);
		}
	}
	return 0;
}
