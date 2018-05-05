#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char get_inverse(char);
bool is_balanced(char *c, int len) {
	
	char stack[len];
	
	long int index=0;
	char push,pop;
	long int tos=0;
	while (index<len) {
		if (tos <0 ) return false;
		if (c[index]=='[' || c[index]=='{' || c[index]=='(') {
			stack[tos]=c[index];
			tos++;	
		} else if (c[index]==']' || c[index]=='}' || c[index]==')') {
			pop=stack[tos-1];
			tos--;
			if (c[index]!=get_inverse(pop)) {
				return false;
			}
		} else {
			return false;
		}
		index++;
	}
	if (tos==0) {
		return true;
	} else {
		return false;
	}	 
}


char get_inverse(char c) {
	 switch(c) {
 	 	case '[':
        	return ']';
        case '{':
            return '}';
        case '(':
          	return ')';
		default:
			return 0;
        }
}


int main(){
    int t;  
    long int len=0;
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        char* expression = (char *)malloc(512000 * sizeof(char));
        scanf("%s",expression);
	len=strlen(expression);
         bool answer = is_balanced(expression,len);
         if(answer)
          printf("YES\n");
         else
          printf("NO\n");
    }
    return 0;
}
