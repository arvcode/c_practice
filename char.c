#include <stdio.h>
#include<string.h>
main() {
	int a;
	int b;
	a=10;
	b=10;
	scanf("%d %d",&a,&b);
 	char c[a+b+1];
	memset(c,'1',a+b);
	c[a+b]='\0';
	printf("strlen is %d \n",strlen(c));
	printf("%s",c);
	free(c);

}
