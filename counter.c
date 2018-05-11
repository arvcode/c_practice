#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();


int check(int n) {

    if (n%2==0) {
        while (n%2==0) {
            n=n/2;
        } 
    }
    if (n==1) return 1;
    else return 0;

}


// Complete the counterGame function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char a[10];
char* counterGame(long n) {
    int test=0;
    int val=0;
    while (n!=1) {
         if (test==0) test=1;
        else test=0;


	if ((n&(n-1))==0) {
            n=n/2;            
        } else {
            val=log2(n);
            val=pow(2,val);
            n=n-val;
        }
	printf("n is %ld \n",n);
    }
    if (test==1) {
        strcpy(a,"Louise");
    } else {
        strcpy(a,"Richard");
    }
    return a;
    

}

int main()
{

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        long n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* result = counterGame(n);

        printf("%s\n", result);
    }


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
