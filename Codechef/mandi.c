#include <stdio.h>
#include <stdlib.h>

void sort(char *arr, int n)
{
	char ch;
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;++j)
		{
			if((arr[j]-'0')>(arr[j+1]-'0'))
			{
				ch=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=ch;
			}
		}
	}
}

int lucky(char *arr, int n)
{
	int asc=0,dec=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[i+n])
		{
			asc++;
		}
		else if(arr[i]<arr[i+n])
		{
			dec++;
		}
	}
	if(asc==n||dec==n)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	char *arr=(char *)malloc(sizeof(char)*(2*n+1));
	scanf("%s",arr);
	sort(arr,n);
	sort(arr+n,n);
	if(lucky(arr,n))
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
}
