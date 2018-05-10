#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int num_ways(int );
int a[36];

int main(){
    int s; 
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int n; 
        scanf("%d",&n);
        a[1]=1;
        a[2]=2;
        a[3]=4;
        printf("%d\n",num_ways(n));
    }
    return 0;
}


int num_ways (int n) {
    int count=0;
    if (n>3 && a[n]>0) {
	return a[n];
    }
    if (n==1 || n==2 || n==3 ) return a[n];
    if (n<=0) return 0;
    a[n]+=num_ways(n-1)+num_ways(n-2)+num_ways(n-3);
    return (a[n]);
       
}
