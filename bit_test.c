/*

Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 ( 0 0 0 1 0 1 1 1 ), it should be converted to 43 ( 0 0 1 0 1 0 1 1 ). Here every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:

The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N, where N is the number of coins.

Output:

Corresponding to each test case, print in a new line, the converted number .

Constraints:

1 . T . 100
1 . N . 100

Example:

Input
2
23
2

Output
43
1

*/


#include<stdio.h>



int main(){
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	short odd=0;
	short even=0;
	c=0;
	printf("Enter the number \n");
	scanf("%d",&a);
	b=a;
	while (a!=0) {
		odd=a&1;
		a>>=1;
		even=a&1;
		a>>=1;
		c|=even;	
		c<<=1;
		c|=odd;
		c<<=1;
		printf("%d%d", even,odd);
	}
	printf("\n");
	while (c!=0) {
		odd=c&1;
		c>>=1;
		d|=odd;
		d<<=1;
		printf("%d",odd);	
	}
	d>>=1;
	printf("\n%d",d);
}











