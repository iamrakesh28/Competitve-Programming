#include <stdio.h>
#include <limits.h>

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		int alice,max_alice=INT_MIN,sum_alice=0;
		int bob,max_bob=INT_MIN,sum_bob=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&alice);
			if(alice>max_alice)
			max_alice=alice;
			sum_alice+=alice;
		}
		sum_alice-=max_alice;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&bob);
			if(bob>max_bob)
			max_bob=bob;
			sum_bob+=bob;
		}
		sum_bob-=max_bob;
		if(sum_alice<sum_bob)
		{
			printf("Alice\n");
		}
		else if(sum_bob<sum_alice)
		{
			printf("Bob\n");
		}
		else
		printf("Draw\n");
	}
	return 0;
}
