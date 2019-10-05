#include <stdio.h>

double losscal(double x,double price,int quant)
{
	double loss,mod;
	mod=price*(x/100+1);
	loss=price-mod*(1-x/100);
	loss=loss*quant;
	return loss;
}

int main()
{
	int q;
	scanf("%d",&q);	
	while(q--)
	{
		int n,price,quant,dis;
		double loss=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&price,&quant,&dis);
			loss+=losscal(dis,price,quant);
		}
		printf("%0.9lf\n",loss);
	}
}
