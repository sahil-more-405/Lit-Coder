https://onlinegdb.com/3lJkZWQEW

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);



/*
 * Complete the 'perfectBreak' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int all_max(int *a,int n,int max)
{
    for(int i=0;i<n;i++)
        if (a[i]!= max)
            return 0;
    return 1;
}
int next_inc_pair(int *a,int n,int max)
{
    int i=n-1;
    if(a[i]!=max)
        a[i]++;
    else 
    {
        while(i!=0 && a[i]==max)
            i--;
        a[i]++;
        while(i<n-1)
        {
            a[i+1] = a[i];
            i++;
        }
    }
    return (!all_max(a,n,max));
}
int is_decresing(int *a,int n)
{
    for(int i=1;i<n;i++)
        if(a[i-1]<a[i])
            return 0;
    return 1;
}
int all_positive(int *a,int n)
{
    for(int i=0;i<n;i++)
        if(a[i]<0)
            return 0;
    return 1;
}
int perfectBreak(int arr_count, int* arr) 
{
    int ans = 0, max=arr[0];
    int b[arr_count],c[arr_count];
    
    for(int i=1;i<arr_count;i++)
        if(arr[i]>max)
            max = arr[i];
    for(int i=0;i<arr_count;i++)
        b[i]=0;
    
    int go_on_b=1;
    while(go_on_b)
    {
        for(int i=0;i<arr_count;i++)
            c[i] = arr[i] - b[i];
        
        if(all_positive(c,arr_count) && is_decresing(c,arr_count))
            ans++;
            
        go_on_b = next_inc_pair(b,arr_count,max);
    }
    //Last one time
    {
        for(int i=0;i<arr_count;i++)
            c[i] = arr[i] - b[i];
        
        if(all_positive(c,arr_count) && is_decresing(c,arr_count))
            ans++;
    }
    return ans;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int arr_count = parse_int(ltrim(rtrim(readline())));

    int* arr = malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++) {
        int arr_item = parse_int(ltrim(rtrim(readline())));

        *(arr + i) = arr_item;
    }

    int result = perfectBreak(arr_count, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
