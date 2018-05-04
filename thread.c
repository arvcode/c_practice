#include<pthread.h>
#include<stdio.h>
#include<string.h>

void * thread_handler (void *);

int main() {
	pthread_t tid[5];
	int ret[5];
	int index=0;
	char a[5][10]={"thread 1", "thread 2", "thread 3", "thread 4" , "thread 5"};
		
	int i[10]={10,11,12,13,14,15,16,17,18,19};

	int *ptr;

	ptr=i;

	printf("i %x %p \n",i,i);

	printf("*i %x %p \n", *i, *i);
	
	printf("&i %x %p \n", &i, &i);

	printf("&i+1 %x %p \n", &i+1, &i+1);

	printf(" *(i+1) %x %p \n", *(i+1), *(i+1));
	
	printf("i+1 %x %p \n", i+1, i+1);

	printf("*ptr %x %p \n",*ptr, *ptr);

	printf("*(ptr+1) %x %p \n",*(ptr+1), *(ptr+1));
	
	printf("ptr %x %p \n",ptr,ptr);

	ptr++;
	
	printf("ptr++ %x %p \n",ptr,ptr);

	memset(ret,0,5);
	
	while (index<5) {
		ret[index]=pthread_create(&tid[index],NULL,thread_handler,(void *) a[index]);
		index++;
	}
	
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);	
	pthread_join(tid[2],NULL);
	pthread_join(tid[3],NULL);
	pthread_join(tid[4],NULL);
	
	printf("Multi dimensional array \n");

	printf("a is %x %p \n",a,a);

	printf("*a is %x %p \n",*a,*a);

	printf("**a is %x %p \n", **a, **a);

	printf("&a is %x %p \n",&a,&a);

	printf("a+1 is %x %p \n",a+1,a+1);

	printf("&a+1 is %x %p \n",&a+1,&a+1);

	printf("*a[2] is %x %p \n",*a[2],*a[2]);

	printf("&a[2] is %x %p \n",&a[2],&a[2]);

	

}




void * thread_handler (void * arg) {
	char *ptr;
	
	ptr=(char*)(arg);
	
	printf("%s\n",ptr);


}
