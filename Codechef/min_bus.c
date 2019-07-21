#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define loop(x) for(int i=0;i<x;++i)

struct people{
	long int p,t,u;
};
typedef struct people people;

int binary(long int *stops,int n,long int val,int *mid)
{
	int begin = 0,middle,end=n-1;
	while(begin!=end)
	{
		middle = (begin+end)/2;
		if(stops[middle]==val)
		{
			return 1;
		}
		else if(stops[middle]>val)
		{
			end = middle;
		}
		else
		{
			begin = middle+1;
		}
	}
	*mid = middle;
	return 0;
}

void min_time(double *time,long int *stops,people *person, int n,int q,long int w,long int v)
{
	double time_left,time_right;
	int left,right,mid,m;
	loop(q)
	{
		if(person[i].u >= v)
		{
			time[i] = (double)(stops[n-1]-person[i].p)/person[i].u;
			//printf("%d %ld %ld %ld\n",i,person[i].u,v,stops[n-1]);
			continue;
		}
		if(binary(stops,n,person[i].p,&mid))
		{// catches 1st bus or not
			if(person[i].t <= (double)person[i].p/v)
			{
				time[i] = (double)(stops[n-1]-person[i].p)/v + (double)person[i].p/v - person[i].t;
			}
			else
			{
			        m = ceil((person[i].t - (double)person[i].p/v)/w);
			        time[i] = (double)(stops[n-1]-person[i].p)/v + (double)person[i].p/v - person[i].t + m*w ;
			}
		}	
		else
		{
			if(stops[mid]>person[i].p)
			{
				left = mid-1;
				right = mid;
			}
			else
			{
				left = mid;
				right = mid+1;
			}	
			//left stop
			if(person[i].t + (double)(person[i].p-stops[left])/person[i].u <= (double)stops[left]/v)
			{
				time_left = (double)(stops[n-1]-stops[left])/v + (double)stops[left]/v - person[i].t+(double)(person[i].p-stops[left])/person[i].u;
			}
			else
			{
			        m = ceil((person[i].t + (double)(person[i].p-stops[left])/person[i].u- (double)person[i].p/v)/w);
			        time_left = (double)(stops[n-1]-person[i].p)/v + (double)person[i].p/v - person[i].t + m*w  + (double)(person[i].p-stops[left])/person[i].u;
			}
			if(person[i].t + (double)(person[i].p-stops[right])/person[i].u <= (double)stops[right]/v)
			{
				time_right = (double)(stops[n-1]-stops[right])/v + (double)stops[right]/v - person[i].t+(double)(person[i].p-stops[right])/person[i].u;
			}
			else
			{
			        m = ceil((person[i].t + (double)(person[i].p-stops[right])/person[i].u- (double)person[i].p/v)/w);
			        time_right = (double)(stops[n-1]-person[i].p)/v + (double)person[i].p/v - person[i].t + m*w  + (double)(person[i].p-stops[right])/person[i].u;
			}
			if(time_left>time_right)
			time[i] = time_right;
			else
			time[i] = time_left;
		}	
	
	}
}

int main()
{
	int n,q;
	scanf("%d",&n);
	long int *stops = (long int *)malloc(sizeof(long int)*n);
	long int w,v;
	for(int i = 0; i<n;++i)
	{
		scanf("%ld",stops+i);
	}
	scanf("%ld%ld%d",&w,&v,&q);
	people *person = (people *)malloc(sizeof(people)*q);
	loop(q)
	{
		scanf("%ld%ld%ld",&person[i].p,&person[i].t,&person[i].u);
	}
	double *time = (double*)malloc(sizeof(double)*q);
	min_time(time,stops,person,n,q,w,v);
	loop(q)
	{
		printf("%0.8lf ",time[i]);
	}
	return 0;
}

