#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int num_ways(int );

int main(){
    int s; 
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int n; 
        scanf("%d",&n);
	printf("%d",num_ways(n));
    }
    return 0;
}


int num_ways (int n) {
    if (n==1) return 1;
    if (n==2) return 2;
    if (n==3) return 4;
    if (n==0) return 0;
    return (num_ways(n-1)+num_ways(n-2)+num_ways(n-3));
       
}
