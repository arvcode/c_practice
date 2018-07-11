/* an error code */
#include<stdio.h>
main() {
	int a=5,b=5,c=5;
	int d=5+5+7*2;
	char z[5+2+2]="string";
	if(sizeof(a)>12) {
	printf("size");
	#define FLAG 1
	#if FLAG
//		#error "size exceeded" 
	#endif
	}
#ifdef FLAG	
	a++,b++,c++;
#endif	
	printf("%d %d %d %d %s %d\n",a,b,c,d,z,sizeof(a));
}
