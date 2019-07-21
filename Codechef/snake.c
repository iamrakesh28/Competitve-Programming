#include<stdio.h>

int steps(int step)
{
	
}
int traversal(int *map, int step, int n, int start)
{
	for(int i=start;i<n*n;++i)
	{
		if(map[i])
		{
			traversal(map,step,n,map[i]);
		}
	}

}

int main()
{
	int n;
	scanf("%d",&n);
	int *map= (int *)calloc(n*n,sizeof(int));
	//Ladder
        //map[]
	return 0;
}
