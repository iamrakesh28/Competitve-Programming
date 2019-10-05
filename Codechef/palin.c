#include <stdio.h>
#include <stdlib.h>


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
	
	int *t=(int *)malloc(sizeof(int)*len);
	int num=1,i=1,gap,back;
	int *xt=t;
	if(len%2)
	{
		/*for(int j=len/2;j<len;++j)
		{
			if(pt[j]-'a'==odnum)
			gap=j+1;
		}*/
	while(*pt!='\0')
	{
		//arr[*pt-'a']++;
		if(*pt-'a'==odnum&&odnum!=-1)
		{		
			//t[len/2]=num;
			*t=len/2+1;
			arr[*pt-'a'][0]--;
			odnum=-1;
			gap=num;
			if(num!=len/2+1)
			num--;
			//t++;
		}
		else
		{
			if(i==len/2+1)
			num++;
			arr[*pt-'a'][0]--;
			if(arr[*pt-'a'][1]==0)
			{
				/*if(i==len/2+1)
			//t[num-1]=t[len-num]=num;
				{
					//*t=gap; //num++;
					*t=num;
					arr[*pt-'a'][1]=len-gap+1;
				}
				else*/
				{
					*t=num;
					arr[*pt-'a'][1]=back=len-num+1;
				}
				
			}
			else
			{
				*t=arr[*pt-'a'][1];
				arr[*pt-'a'][1]=0;
				
			}			
		}
		pt++;
		num++;
		t++;
		i++;
	}
	}
	else
	while(*pt!='\0')
	{
			arr[*pt-'a'][0]--;
			if(arr[*pt-'a'][1]==0)
			{
				arr[*pt-'a'][1]=len-num+1;
			//t[num-1]=t[len-num]=num;
				*t=num;
			}
			else
			{
				*t=arr[*pt-'a'][1];
				arr[*pt-'a'][1]=0;
				
			}			
		pt++;
		num++;
		t++;
	}
	for(int i=0;i<len;++i)
	{
		printf("%d ",xt[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	int q;
	char string[100000];
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int **arr=(int **)malloc(26*sizeof(int*));
		for(int j=0;j<26;++j)
		arr[j]=(int *)calloc(2,sizeof(int));
		scanf("%s",string);
		int result=count(string,arr);
		if(result)
		printf("%d\n",result);
	}
	return 0;
}
