#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void check_prime (int n, char *s);

int main(){
    int p;
    char s[10];
    scanf("%d",&p);
    for(int a0 = 0; a0 < p; a0++){
        int n;
        scanf("%d",&n);
        check_prime(n,s);
        printf("%s \n",s);
    }
    return 0;
}

void check_prime (int n, char *s) {
    int index=0;
    if (n==1 || n==0) {
	strcpy(s,"Not prime");
	return;
	}  
    for (index=2;index<=10;index++) {
        if (n%index==0 && n!=index) {
            strcpy(s,"Not prime");
            break;
        } 
    }
    if (index==11) strcpy(s,"Prime");
}
   
