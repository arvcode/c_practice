#include<stdio.h>

main() {
	char a='a';
	char b='b';

	printf("%c %c %d %d \n",a,b,a,b);
	a^=b;
	printf("a^=b ->%c %d \n",a,a);
	b^=a;
	printf("b^=a ->%c %d \n",b,b);
	a^=b;
	printf("a^=b ->%c %d \n",a,a);

}
