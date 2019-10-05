#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
		int n,i;
  		scanf("%d",&n);
  		for(i=1;n>=0;++i)
        {
          	n=n-i*(i+1)/2;
        }
  		printf("%d\n",i-2);
       
    return 0;
}
