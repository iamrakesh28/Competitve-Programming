#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

struct dim{
	double x,y,z;
};

double angle_alpha(double area)
{
	double sq =sqrt(3),val=acos(area/sq) ;
	double al = atan(1/sq);
	return al + val;
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		double area,angle;
		double sq =sqrt(2);
		scanf("%lf",&area);
		angle = angle_alpha(area);
		struct dim *ab = (struct dim *)malloc(sizeof(struct dim)*3);
		//printf("%g ",angle);
		ab[0].x = 0.5;
		ab[0].y = 0;
		ab[0].z = 0;
		ab[1].x = 0;
		ab[1].y = 0.5/sq;
		ab[1].z = 0;
		ab[2].x = 0.5;
		ab[2].y = -0.5/sq;
		ab[2].z = 0.5 /sq;
		for(int j=0;j<3;++j)
		{
			ab[j].x = ab[j].x* sin(angle) - ab[j].y * cos(angle);
			ab[j].y = ab[j].x* cos(angle) + ab[j].y * sin(angle);
		}
		printf("Case #%d:\n ",i);
		for(int j=0;j<3;++j)
		{
			printf("%g %g %g\n",ab[j].x,ab[j].y,ab[j].z);
		}
		
	}

}
