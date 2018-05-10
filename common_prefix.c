/*
Given a array of n strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer n. Next line has space separated n strings. 

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1<=T<=200
1<=n<=100
1<=|S|<=100

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap
*/

#include<stdio.h>
#include<stdlib.h>

char * prefix_finder(char**,int);



int main() {
	int num_test=0;
	int num_char=0;
	int index_t,index_c;
	char ***ptr;

	index_t=index_c=0;

	printf("Enter the number of test cases \n");
	scanf("%d",&num_test);
	ptr=malloc(sizeof(char)*num_test);

	while(index_t<num_test) {
		printf("Enter the number of strings \n");
		scanf("%d",&num_char);	
		ptr[index_t]=malloc(sizeof(char)*num_char);
		index_c=0;	
		while(index_c<num_char) {
			ptr[index_t][index_c]=malloc(sizeof(char)*100);
			scanf("%s",ptr[index_t][index_c]);
			index_c++;
		}
		printf("%s",prefix_finder(ptr[index_t],index_c-1));
		index_t++;
	}	
	
}

char* prefix_finder(char **ptr, int num_str) {

	char *string1;
	char *string2;
	int string_index, char_index;
	int str_len1, str_len2;
	char substring[100];
	char *tmp_count;
	
	str_len1=str_len2=string_index=char_index=0;
	tmp_count=substring;
	while (string_index<num_str) {
		if (string_index==0) {
			string1=ptr[string_index];
			string2=ptr[string_index+1];
		} else {
			string1=substring;
			string2=ptr[string_index+1];
		}
		char_index=0;
		while (*string1==*string2) {
			substring[char_index]=*string2;
			string1++;
			string2++;
			char_index++;		
		}
		substring[char_index]='\0';
		string_index++;
	}	

		printf("Longest prefix is %s \n",substring);
		return substring;
}

