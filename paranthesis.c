/*
Given an expression string exp, examine whether the pairs and the orders of .{.,.}.,.(.,.).,.[.,.]. are correct in exp.
For example, the program should print 'balanced' for exp = .[()]{}{[()()]()}. and 'not balanced' for exp = .[(]).

 

Input:

The first line of input contains an integer T denoting the number of test cases. 
Each test case consist of a string of expression, in a separate line.

Output:

Print 'balanced' without quotes if pair of parenthesis are balanced else print 'not balanced' in a separate line.


Constraints:

1 . T . 100
1 . |s| . 100


Example:

Input:
3
{([])}
()
()[]

Output:
balanced
balanced
balanced
*/


#include<stdio.h>

char * paranthesis_checker(char *);
char get_inverse(char);

int main () {

	char input[100];
	int n_test;
	int s_len;
	int index=0;
	printf("Enter test cases \n");
	scanf("%d",&n_test);	
	while (index !=n_test) {
		printf("Enter string \n");
		scanf("%s",input);
		printf("-> %s",paranthesis_checker(input));
		index++;
	}


}

char * paranthesis_checker(char * c) {
	int length;
	int index=0;
	char *un="unbalanced";
	char *bl="balanced";
	char *np="unknown paranthesis";
	char front,back;
	int  match_count=0;
	while(c[index]!='\0') {
		index++;
	}
	length=index;
	index=0;
	while (index !=length) {
		front=get_inverse(c[index]);
		if (front==c[index+1]) {
			match_count++;
		}
		index=index+2;	 	
	}
	printf("index is %d \n", index);
	printf("match count %d \n",match_count);
	if (index/2==match_count) {
		return bl;
	}

	index=0;
	while(index<length/2) {
		front=get_inverse(c[index]);
		back=c[length-index-1];
		if (front!=back) {
			return un;
		}
		index++;
	}
	return bl;
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










