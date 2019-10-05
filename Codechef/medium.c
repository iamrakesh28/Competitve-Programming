#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

void sort(int n, int *arr,int *dum)
{
    int num;
    for(int i=0;i<n-1;++i)
    {
        for(int j=0;j<n-1-i;++j)
        {
            if(arr[j]>arr[j+1])
            {
                num=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=num;
                num=dum[j];
                dum[j]=dum[j+1];
                dum[j+1]=num;
            }
        }
    }
    
}

/*
 * Complete the function below.
 */
int count(int *S,int *K, int *R,int n,int *start,int cl)
{
    int  num=0;
    float sq=sqrt(2);
    for(int i=*start;i<n;++i,(*start)++)
    {
        if(sq*S[i]<2*R[cl])
        {
            num+=K[i];
        }
        else
        {
            //(*start)++;
            break;
        }
    }
    return num;
}
int maximumPackages(int n, int* S, int K_size, int* K, int m, int* R, int C_size, int* C) {
    // Return the maximum number of packages that can be put in the containers.
    sort(n,S,K);
    sort(m,R,C);
    int start=0,sum=0;
    int *arr=(int *)calloc(m,sizeof(int));
    arr[0]=count(S,K,R,n,&start,0);
    if(arr[0]<=C[0])
    {
        arr[0]=0;
    }
    else
    {
        arr[0]=arr[0]-C[0];
    }
    for(int i=1;i<m;++i)
    {
        int store=count(S,K,R,n,&start,i);
        arr[i]+=arr[i-1];//+count(S,K,R,n,&start,i);
        if(arr[i]+store<=C[i])
        {
            arr[i]=0;
        }
        else
        {
            arr[i]=arr[i]+store-C[i];
        }
    }
    for(int i=0;i<n;++i)
    {
        sum+=K[i];
    }
    //fprintf(f, "hello\n");
    return sum-arr[m-1];
}


int main()
{
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* S_size_endptr;
    char* S_size_str = readline();
    int S_size = strtol(S_size_str, &S_size_endptr, 10);

    if (S_size_endptr == S_size_str || *S_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** S_str = split_string(readline());

    int S[S_size];
    for (int S_i = 0; S_i < S_size; S_i++) {
        char* S_item_endptr;
        char* S_item_str = S_str[S_i];
        int S_item = strtol(S_item_str, &S_item_endptr, 10);

        if (S_item_endptr == S_item_str || *S_item_endptr != '\0') { exit(EXIT_FAILURE); }

        S[S_i] = S_item;
    }

    char* K_size_endptr;
    char* K_size_str = readline();
    int K_size = strtol(K_size_str, &K_size_endptr, 10);

    if (K_size_endptr == K_size_str || *K_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** K_str = split_string(readline());

    int K[K_size];
    for (int K_i = 0; K_i < K_size; K_i++) {
        char* K_item_endptr;
        char* K_item_str = K_str[K_i];
        int K_item = strtol(K_item_str, &K_item_endptr, 10);

        if (K_item_endptr == K_item_str || *K_item_endptr != '\0') { exit(EXIT_FAILURE); }

        K[K_i] = K_item;
    }

    char* R_size_endptr;
    char* R_size_str = readline();
    int R_size = strtol(R_size_str, &R_size_endptr, 10);

    if (R_size_endptr == R_size_str || *R_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** R_str = split_string(readline());

    int R[R_size];
    for (int R_i = 0; R_i < R_size; R_i++) {
        char* R_item_endptr;
        char* R_item_str = R_str[R_i];
        int R_item = strtol(R_item_str, &R_item_endptr, 10);

        if (R_item_endptr == R_item_str || *R_item_endptr != '\0') { exit(EXIT_FAILURE); }

        R[R_i] = R_item;
    }

    char* C_size_endptr;
    char* C_size_str = readline();
    int C_size = strtol(C_size_str, &C_size_endptr, 10);

    if (C_size_endptr == C_size_str || *C_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** C_str = split_string(readline());

    int C[C_size];
    for (int C_i = 0; C_i < C_size; C_i++) {
        char* C_item_endptr;
        char* C_item_str = C_str[C_i];
        int C_item = strtol(C_item_str, &C_item_endptr, 10);

        if (C_item_endptr == C_item_str || *C_item_endptr != '\0') { exit(EXIT_FAILURE); }

        C[C_i] = C_item;
    }

    int result = maximumPackages(S_size, S, K_size, K, R_size, R, C_size, C);

    fprintf(f, "%d\n", result);


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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
