/*After setting up the area. Chandu wanted all his toys to be stacked there in that area. So that all of them are accessible easily. Currently, He is having N stacks of toys each with height

(assuming all toys are of same height).Chandu did not like the configuration much and want to change the height of each stack. To increase the height of a particular stack he can add some toys to it and to decrease the height he can take out some toys from that stack. Chandu, knows that he requires X units of effort for putting up an item onto the stack and Y units of effort for removing it. Help, chandu in setting up his toys.

Input:

First Line of input contains an integer t, which is the number of test cases. then, t lines follow where first line of each test case contains three integers N, X and Y then N lines follow containing two integers each
and (Initial height of stack and final height of

stack.)

Output:

Output an integer which is the minimum effort required.

NOTE: he just need to make stacks of given height. Not necessarily each stack should be made from its corresponding stack.

Constraints:



SAMPLE INPUT

1
3 6 4
3 1
1 2
1 2

SAMPLE OUTPUT

10

Explanation

Here, He is having 3 stacks initially of height
and 1 He can take out one toy from first stack to get a stack with two toys with 4 units of effort. He can put toy on second stack to get a stack with two toys with 6 units of effort. Total effort = units. After the two operations he will have three stacks with required heights. */


#include<stdio.h>
#include<stdlib.h>
int find_min(int **,int, int ,int);

int main() {
    int n_test;
    int test_case[3];
    int **a;
    int index=0;
    int index1=0;
    int index2=0;
    scanf("%d",&n_test);
    for (index=0;index<n_test;index++) {
	for (index2=0;index2<3;index2++) {
        	scanf("%d",&test_case[index2]);
	}
        a=malloc(sizeof(int)*test_case[0]);
        for (index1=0;index1<test_case[0];index1++) {
            a[index1]=malloc(sizeof(int)*2);
	    for (index2=0;index2<2;index2++) {	
            		scanf("%d",&a[index1][index2]);
		}
        }
	
    	printf("%d",find_min(a,test_case[0],test_case[1],test_case[2]));
    }
    
}

int find_min (int **a,int n,int x, int y) {
    
    int put_effort=x;
    int pull_effort=y;
    int effort=0;
    int index=0;
    int val=0;
    int val_1=0;
    while (index<n) {
       val^=a[index][1];
	   index++; 
    }

    for (index=0;index<n;index++) {
		if (a[index][0]>a[index][1]) {
			
		} else if (a[index][1]>a[index][0]) {
			
		}

    }
    return effort;
    
}


