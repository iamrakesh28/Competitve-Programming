#include <stdio.h>
#include <stdlib.h>

int maxi(int a,int b)
{
    return a>b ? a: b;
}
// Complete the flippingMatrix function below.
long int flippingMatrix(int row, int col, int** matrix) {
    
    long int max=0;
    for(int i=0;i<row/2;++i)
    {
        for(int j=0;j<col/2;++j)
        {
               max += maxi(maxi(matrix[row-1-i][j],matrix[row-1-i][col-1-j]),maxi(matrix[i][j],matrix[i][col-1-j]));
        }
    }
    return max;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		int **arr = (int **)malloc(sizeof(int*)*2*n);
		for(int i=0;i<2*n;++i)
		{
			arr[i] = (int*)malloc(sizeof(int)*2*n);
			for(int j=0;j<2*n;++j)
			{
				scanf("%d",arr[i]+j);
			}
		}
		printf("%ld\n",flippingMatrix(2*n,2*n, arr));
	}
	return 0;
}
