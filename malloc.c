int main() {
	char *a;

	a=malloc(2);
	memset(a,1,2);
	printf("a is %p *a is %d \n",a,*a);
	a++;
	printf("a is %p *a is %d \n",a,*a);
	a++;
	printf("a is %p *a is %d \n",a,*a);
	a--;
	printf("a is %p *a is %d \n",a,*a);
	a--;
	printf("a is %p *a is %d \n",a,*a);
	a--;
	printf("a is %p *a is %d \n",a,*a);
}
