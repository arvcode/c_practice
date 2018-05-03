/*
Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output sho
uld be 3. 

If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list. 
There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return data of linked list.  If linked list is empty, then return -1.

Constraints:
1 <=T<= 30
1 <=N<= 100
1 <=value<= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
3
7

 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console, and should not print anything on stdout/console. The task is to complete the function specified, and not to write the full code

*/


/* --NOTE -- */

/* problem statement deviation - will accept from input and print */


#include<stdio.h>

typedef struct ll {
	int data;
	struct ll *next;
}ll_t;


int find_middle(ll_t *i, int);

ll_t * insert(int );

int print_list(ll_t *);

int main() {
	int n_test_case;
	int length;
	int max_value;
	int element;
	int index_t, index_a;
	ll_t *list;
	ll_t *head;

	index_t=index_a=0;
	printf("Enter test case \n");
	scanf("%d",&n_test_case);
	
	while (index_t<n_test_case) {
		printf("Enter size \n");
		scanf("%d",&length);
		while (index_a<length) {
			printf("Enter elements \n");
			scanf("%d",&element);
			if (index_a==0) {
				head=insert(element);
				list=head;	
			} else {
				list->next=insert(element);
				list=list->next;
			}
			index_a++;
		}
		print_list(head);
		printf("\n middle element %d \n",find_middle(head,index_a));
		index_t++;
	}	
}


ll_t * insert(int a) {

	ll_t *ptr=NULL;
	ptr=(ll_t*)malloc(sizeof(ll_t));
	ptr->data=a;
	ptr->next=NULL;
	return ptr;

}

int print_list (ll_t * list) {
	ll_t *ptr;
	ptr=list;
	while (ptr !=NULL) {
		printf("%d ", ptr->data);
		ptr=ptr->next;
	}
	return 0;
}


int find_middle(ll_t * list,int length) {
	
	ll_t *ptr;
	int middle=0;
	int index=0;
	ptr=list;
	if (middle%2==0) {
		middle=length/2;
	} else {
		middle=(length/2)+1;
	}	
	
	while (index<middle) {
		ptr=ptr->next;
		index++;		
	}
	return (ptr->data);

}
