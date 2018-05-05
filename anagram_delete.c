/*
 Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, and , that may or may not be of the same length, determine the minimum number of character deletions required to make and anagrams. Any characters can be deleted from either of the strings. 
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int anagram_delete(char *, char *);
int main(){
    char* a = (char *)malloc(512000 * sizeof(char));
    scanf("%s",a);
    char* b = (char *)malloc(512000 * sizeof(char));
    scanf("%s",b);
    printf("%d",anagram_delete(a,b));
    return 0;
}

int anagram_delete(char *a, char *b) {
    int map_a[26]={0};
    int map_b[26]={0};
    int index=0;
    int count;
    int len_a,len_b;
    len_a=strlen(a);
    len_b=strlen(b);
        while (index<len_a) {
            map_a[a[index]-'a']+=1;
            index++;
        }
        index=0;
      while (index<len_b) {
            map_b[b[index]-'a']+=1;
            index++;
        }
    index=0;
    count=0;
    while (index<26) {
        if(map_a[index]!=map_b[index]) {
		if (map_a[index]>map_b[index]) {
			count+=map_a[index]-map_b[index];
		} else {
			count+=map_b[index]-map_a[index];
		}

        }
        index++;        
    }
    
    return count;
    
    
}
