#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*brute force O(N2) - error */
char find_recurring_char(char *);
/*O(N) */
char make_map(char *);

int main () {

	char string[100];
	printf("Enter the string \n");
	scanf("%s",string);
	
	printf("recurring char is %c\n",find_recurring_char(string));
	printf("recurring char is %c \n",make_map(string));

}

char find_recurring_char (char * c) {
	int index=0;
	int index1=0;
	int length=0;
	while(c[index]!=0) {
		index++;
	}
	length=index;
	index=0;
	index1=1;
	while (index <length) {
		if (c[index]==c[index1]) {
			return c[index];	
		} else {
			if(index1<length) {
				index1++;
				continue;
			}
		}			
		index++;
		index1=index+1;
	}
	return 0;
}


char make_map(char *c) {

	int index=0;
	int index1=0;
	int length=0;
	char map[255];
	while(c[index]!=0) {
        	index++;
        }
	length=index;
	index=0;
	memset(map,0,255);
	while (index <length) {
		map[c[index]]+=1;
		if (map[c[index]]>1) {
			return c[index];
		}
		index++;
	}

	return 0;
}
