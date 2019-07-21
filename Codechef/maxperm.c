#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define d 26
#define q 1009
char* readline();


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
int ismatch(char *input, char *window,char *mat_num)
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
int hash(int start, int m,int *arr)
{
    int h=0;
    for(int i=start;i<start+m;++i)
    {
        h=(h*d+arr[i]-'a');
    }
    return h;
}
void allocate(char **string, int *hash_id, int *max_time,int p,int *start,int begin, int end,char *w,int *max)
{
    //hash_id[start]=p;
    //(*start)++;
    for(int i=0;i<=*start;++i)
    {
        if(hash_id[i]==p)
        {
            max_time[i]++;
            if(max_time>*max)
            {
                *max=max_time;
            }
            return ;
        }
    }
    (*start)++;
    hash_id[*start]=p;
    string[*start]=(char *)malloc(20001*sizeof(char));
    for(int i=begin;i<end;++i)
    {
        string[*start][i]=w[i];
    }
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
int string_match(int max,char **string,int start,int *max_time)
{
       int i;
       for(i=0;i<=start;++i)
       {
           if(max_time[i]==max)
               break;
       }
       for(int j=i+1;j<=start;++j)
       {
            if(max_time[j]==max)
            {
                if(strcmp(string[i],string[j])>0)
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
    int m=0,max=0,i=0,match,p=0,start=0;
    int *max_time=(int *)calloc(q,sizeof(int));
    int *hash_id=(int *)calloc(q,sizeof(int));
    char **string=(char **)malloc(sizeof(char *)*q);
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
       allocate(string,hash_id,max_time,p,&start,0,m,w,&max);
    }
    int n=strlen(s);
    for(int j=m;j<n;++j)
    {
        window[s[j-m]-'a']--;
        if(input[s[j-m]-'a']==window[s[j-m]-'a'])
        {
            match++;
            mat-num[s[j-m]-'a']=1;
        }
        else if(mat-num[s[j-m]-'a'])
            match--;
        window[s[j]-'a']++;
         if(input[s[j]-'a']==window[s[j]-'a'])
         {
             match++;
             mat-num[s[j]-'a']=1;
         }
        else if(mat-num[s[j]-'a'])
            match--;
        if(match==26)
        {
            p=hash(j,m+j,s);
            allocate(string,hash_id,max_time,p,&start,j,j+m,w,&max);
        }
                    
    }
    if(max==0)
        return "-1";
    int time=check(max,max_time,start);
    if(time==1)
    {
        int rak;
        for(int i=0;i<=start;++i)
        {
            if(max_time[i]==max)
            {
                rak=i;
                break;
            }
        }
        return string[rak];
    }
    else
    {
       int rak= string_match(max,string,start,max_time);
        return string[rak];
    }
}


int main()
{
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* w = readline();

        char* s = readline();

        char* result = maximumPermutation(w, s);

        fprintf(f, "%s\n", result);

    }


    fclose(f);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
