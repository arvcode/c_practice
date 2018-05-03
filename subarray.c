/* Problem statement *

Given an array of size n-1 and given that there are numbers from 1 to n with one missing, the missing number is to be found.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N.
The second line of each test case contains N-1 input C[i],numbers in array.

Output:

Print the missing number in array.

Constraints:

1 . T . 200
1 . N . 1000
1 . C[i] . 1000

Example:

Input
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output
4
9

*/

/* --NOTE -- 
 * Input is modified */



#include<stdio.h>

int subarray(int **ptr, int,int);

int main() {
	int num_test, array_size;
	int max_size;

	int t_index=0;
	int a_index=0;
	int **ptr;
	num_test=array_size=max_size=0;
	max_size=1000;
	printf("enter no of test cases \n");
	scanf("%d",&num_test);
	ptr=(int**)malloc(sizeof(int)*num_test);
	
	while(t_index !=num_test) {
		printf("enter array size \n");
		scanf("%d",&array_size);
		if (array_size >max_size) continue;
	
		ptr[t_index]=(int*)malloc(sizeof(int)*array_size);	
		a_index=0;
		printf("Enter array value \n");
		while(a_index !=array_size) {
			scanf("%d",&ptr[t_index][a_index]);	
			a_index++;
		}
		printf("Missing number is %d \n",subarray(ptr,array_size,t_index));	
		t_index++;			
	}

	free(ptr);
}

int subarray(int** ptr,int index, int t_index) {
	int peek=0;
	int index1=0;
	int sum=0;	
	while (index1<=index) {
		sum+=ptr[t_index][index1];		
		index1++;
	}
	index1=0;
	while(index1<=index) {
		peek+=index1;
		index1++;
	}
	return (peek-sum);

}

