#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int ascii_to_int (char c) {
	if (c=='1') {
		return 1;
	} else if (c=='0') {
		return 0;
	}
    return 0;
}
char int_to_ascii (int n) {
	if (n==0) {
		return '0';	
	} else if (n==1) {
		return '1';
	}
    return '0';
}
 

char* cipher(int k, char* s, int n) {
        int index=0;
        int val=0;
	int index1=0;
        char *c;
	char tc=0;
        c=(char*)malloc((n+1)*sizeof(char));
        memset(c,'0',n+1);
        c[0]=s[0];
	c[n]='\0';
	c[n-1]=s[k+n-2];
	    if (c[0]=='0') {
	    c[1]=s[1];
	    index=2;
            while (index<k) {
                c[index]=ascii_to_int(c[index-1])^ascii_to_int(c[index-2]);
                c[index]=int_to_ascii(c[index]);
                index++;
            }
        } else if (c[0]=='1') {
	    index=1;
            while (index<k) {
                c[index]=1^ascii_to_int(s[index]);
                c[index]=int_to_ascii(c[index]);
                index++;
            }
        }
	index1=0;
	while (index <n-1) {
		index1=1;
		tc=0;
		while (index1<k) {
			tc^=ascii_to_int(c[index-index1]);
			index1++;	
		}
		c[index]=tc^ascii_to_int(s[index]);
		c[index]=int_to_ascii(c[index]);
		index++;
	}
	    return c;
    
    
    
}

int main() {
    int n; 
    int k; 
    scanf("%i %i", &n, &k);
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int result_size;
    char* result = cipher(k, s,n);
    printf("%s\n", result);
    return 0;
}
