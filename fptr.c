#include<stdio.h>


void fun1 (int a) {
	a=a+1;
	printf("%d \n",a);

}

int main() {

	void (*f)(int)=&fun1;
	f(10);

}
