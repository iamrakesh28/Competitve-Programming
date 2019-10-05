#include <stdio.h>
#include <stdlib.h>

void print(char *,int **,int ,int );
int count(char *string, int **arr)
{
	int sum=0,len=0,odnum;
	char *pt=string;
	while(*string!='\0')
	{
		arr[*string-'a'][0]++;
		len++;
		string++;
	}
	int odd=0;
	string=pt;
	for(int i=0;i<26;++i)
	{
		if(arr[i][0]%2)
		{
			odd++;
			odnum=i;
		}
	}
	if(odd>1)
	return -1;
	else if((odd==1)&&(len%2==0))
		return -1;
	else if((odd==0)&&(len%2))
		return -1;
	print(pt,arr,len,odnum);
	return 0;
}	
void print(char *pt, int **arr,int len,int odnum)
{
	int *t=(int *)malloc(sizeof(int)*len);
	int num=1;
	int *xt=t;
	if(len%2)
	{
	while(*pt!='\0')
	{
		if(*pt-'a'==odnum&&odnum!=-1)
		{		
			*t=len/2+1;
			arr[*pt-'a'][0]--;
			odnum=-1;
			if(num==len/2+1)
			num++;
		}
		else
		{
			if(num==len/2+1)
			num++;
			//arr[*pt-'a'][0]--;
			if(arr[*pt-'a'][1]==0)
			{
				{
					*t=num;
					arr[*pt-'a'][1]=len-num+1;
					num++;
				}
				
			}
			else
			{
				*t=arr[*pt-'a'][1];
				arr[*pt-'a'][1]=0;
				
			}			
		}
		pt++;
		//num++;
		t++;
		//i++;
	}
	}
	else
	while(*pt!='\0')
	{
			//arr[*pt-'a'][0]--;
			if(arr[*pt-'a'][1]==0)
			{
				{
					*t=num;
					arr[*pt-'a'][1]=len-num+1;
					num++;
				}
				
			}
			else
			{
				*t=arr[*pt-'a'][1];
				arr[*pt-'a'][1]=0;
				
			}			

		pt++;
		//num++;
		t++;
		//i++;
	}
	int *pri=(int *)malloc(sizeof(int)*len);
	for(int i=0;i<len;++i)
	{
		pri[xt[i]-1]=i+1;	
	}
	for(int i=0;i<len;++i)
	{
		printf("%d ",pri[i]);
	}
	//printf("%s",pri);
	printf("\n");
	return ;
}
int main()
{
	int q;
	char *string=(char *)malloc(100000*sizeof(char));
	int **arr=(int **)malloc(26*sizeof(int*));
	for(int j=0;j<26;++j)
	arr[j]=(int *)calloc(2,sizeof(int));
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		for(int j=0;j<26;++j)
		arr[j][0]=arr[j][1]=0;
		scanf("%s",string);
		int result=count(string,arr);
		if(result)
		printf("%d\n",result);
	}
	return 0;
}
