#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n,count=0,max=0;
  	scanf("%d",&n);
  	char **arr=(char **)malloc(sizeof(char *)*1000);
  	arr[0]=(char *)malloc(sizeof(char)*80);
  	char line[80],*pt,read[80];
  	for(int i=0;i<n;++i)
    {
   		
      	fgets(line,80,stdin);
      	sscanf(line,"%s",read);
	//char ch=getchar();
      	if(strcmp(read,"pwd")==0)
        {
		printf("hello\n");
          	printf("/");
          	for(int j=0;j<count;++j)
            {
              printf("%s/",arr[j]);
            }
          	printf("\n");
        }
      	else 
        {
          	pt=line;
          	pt+=strlen(read)+1;
          	if(*pt=='/')
          	while(*pt!='\0')
            {
              
          	  sscanf(pt,"%[^/]s",read);
              if(strcmp(read,"..")==0)
              {	
                	count--;
              }
              else
              {
          	  strcpy(arr[count],read);
              count++;
              }
              pt+=strlen(read)+1;
              if(max<count)
                arr[++max]=(char *)malloc(sizeof(char)*80);
            }
          	else
              count --;
        }
          
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}