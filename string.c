#include<stdio.h>

int * ptr_int (int *, int);

char * ptr_char (char *, char *);

main() {

	int a=0;
	int *ptr=NULL;
	int b=0;
	char *as="string";
	char bs[10]="str";
	char *p=NULL;

	p=ptr_char(as,bs);
	ptr=ptr_int(&a,b);
	printf("%d \n",*ptr);
	printf("%s \n",p);


}



int * ptr_int (int *a , int b) {

	int c=0;
	int *ptr;
	c=b;
	ptr=&c;
	b=b+1;
	
	*ptr=*ptr+1;
	return ptr;
}



char * ptr_char(char *a, char *b) {

	char *c=a;
	char *d="hello";
	return d;

} 
