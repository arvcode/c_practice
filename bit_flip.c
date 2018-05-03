/*
You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a and b.

Output:

Print the number of bits needed to be flipped.

Constraints:

1 . T . 100
1 . a,b . 1000

Example:

Example:
Input
1
10 20

Output
4
 

Explanation:

A  = 1001001
B  = 0010101
No of bits need to flipped = set bit count i.e. 4*/




#include<stdio.h>

int main () {
	unsigned int a;
	unsigned int b;
	
	unsigned int c;
	short d;
	short count;

	printf("Enter a b\n");
	scanf("%d %d",&a,&b);
	c=a^b;
	count=0;	
	while (c!=0) {
		d=c&1;
		if (d==1) {
			count++;
		}	
		c>>=1;
	}	
	printf("Number of bit flips is %d",count);	







}




