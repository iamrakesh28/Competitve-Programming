#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



#define d 26
#define q 30029


/*
 * Complete the function below.
 * Please either make the string static or allocate on the heap in the function. For example,
 * static char str[] = "hello world";
 * return str;
 *
 *
 * char* str = "hello world";
 * return str;
 *
 */
int ismatch(int *input, int *window,int *mat_num)
{
    int match=0;
    for(int i=0;i<26;++i)
    {
        if(input[i]==window[i])
        {
            mat_num[i]=1;
            match++;
        }
    }
    return match;
}
int hash(int start, int m,char *arr)
{
    int h=0;
    for(int i=start;i<m;++i)
    {
        h=(h*d+arr[i]-'a')%q;
    }
    return h;
}
int str(int *string, int start,int end, char *w)
{
    for(int i=start,j=string[0];i<end;++i,++j)
    {
        if(w[j]!=w[i])
        {
            return 0;
        }
    }
      return 1;
}
void allocate(int **string, int *hash_id, int *max_time,int p,int *start,int begin, int end,char *w,int *max)
{
       if(*max==-1)
           *max=0;
    for(int i=0;i<=*start;++i)
    {
        if(hash_id[i]==p)
        {
            if(str(string[i],begin,end,w))
            {
            max_time[i]++;
            if(max_time[i]>*max)
            {
                *max=max_time[i];
            }
            return ;
            }
            else
                break;
        }
    }
    (*start)++;
    hash_id[*start]=p;
    string[*start]=(int *)malloc(2*sizeof(int));
    string[*start][0]=begin;
    string[*start][1]=end;
    /*for(int i=begin,j=0;i<end;++i,++j)
    {
        string[*start][j]=w[i];
    }*/
    return ;
}
int check(int max,int *max_time,int start)
{
        int count=0;
        for(int i=0;i<=start;++i)
        {
            if(max_time[i]==max)
                count++;
        }
    return count;
}
int stcmp(int start,int begin,char *w,int m)
{
    for(int i=start,j=begin;i<m+start;++i,j++)
    {
        if(w[i]-w[j]!=0)
        {
            return w[i]-w[j];
        }
    }
    return 0;
}
int string_match(int max,int **string,int start,int *max_time,int m,char *w)
{
       int i;
       for(i=0;i<start;++i)
       {
           if(max_time[i]==max)
               break;
       }
       for(int j=i+1;j<=start;++j)
       {
            if(max_time[j]==max)
            {
                if(stcmp(string[i][0],string[j][0],w,m)>0)
                    i=j;
            }
       }
    return i;
}
char* maximumPermutation(char* w, char* s) {
    // Return the string representing the answer.
    int *input=(int *)calloc(26,sizeof(int));
    int *window=(int *)calloc(26,sizeof(int));
    int *mat_num=(int *)calloc(26,sizeof(int));
    int m=0,max=-1,i=0,match,p,start=-1,h=1;;
    int *max_time=(int *)calloc(q,sizeof(int));
    int *hash_id=(int *)calloc(q,sizeof(int));
    int **string=(int **)malloc(sizeof(int *)*q);
    while(*w!='\0')
    {
        input[*w-'a']++;
        w++;
        m++;
    }
    while(i<m)
    {
        window[s[i]-'a']++;
        i++;   
    }
    match=ismatch(input,window,mat_num);
    if(match==26)
    {
       p=hash(0,m,s);
       allocate(string,hash_id,max_time,p,&start,0,m,s,&max);
    }
    for(int i=0;i<m-1;++i)
        h=(h*d)%q;
    int n=strlen(s);
    for(int j=m;j<n;++j)
    {
        p = (d*(p - (s[j-m]-'a')*h) + s[j]-'a')%q;
        if(p<0)
            p=p+q;
        window[s[j-m]-'a']--;
        if(input[s[j-m]-'a']==window[s[j-m]-'a'])
        {
            match++;
            mat_num[s[j-m]-'a']=1;
        }
        else if(mat_num[s[j-m]-'a'])
            {	
			match--;
			mat_num[s[j-m]-'a']=0;
	    }
        window[s[j]-'a']++;
         if(input[s[j]-'a']==window[s[j]-'a'])
         {
             match++;
             mat_num[s[j]-'a']=1;
         }
        else if(mat_num[s[j]-'a'])
           {
		 match--;
		mat_num[s[j]-'a']=0;
	   }
	printf("-%d-\n",p);
        if(match==26)
        {
            p=hash(j-m+1,j+1,s);
            allocate(string,hash_id,max_time,p,&start,j-m+1,j+1,s,&max);
	    printf("=%d=",p);
        }
                    
    }
    if(max==-1)
        return "-1";
    int time=check(max,max_time,start);
    char *str_ret=(char*)malloc(20001*sizeof(char));
    int rak;
    if(time==1)
    {
        //int rak;
        for(int i=0;i<=start;++i)
        {
            if(max_time[i]==max)
            {
                rak=i;
                break;
            }
        }
       
    }
    else
    {
       rak= string_match(max,string,start,max_time,m,s);
   }
     for(int i=0,j=string[rak][0];i<m;++i,j++)
        {
            str_ret[i]=s[j];
        }
	//printf("%d",rak);
        return str_ret;
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char *w=(char *)malloc(sizeof(char)*20001);
		char *s=(char *)malloc(sizeof(char)*200001);
		scanf("%s%s",w,s);
    		char* result = maximumPermutation(w, s);
    		fprintf(stdout, "%s\n", result);
	}
    return 0;
}

