/*
 * int pthread_create(pthread_t *, const pthread_attr_t *, void * (*)(void *), void *);
   void pthread_exit(void *);
   int pthread_join(pthread_t , void **); 
   int pthread_attr_getstacksize(pthread_attr_t *, size_t *);
   int pthread_attr_setstacksize(pthread_attr_t *, size_t);
   int pthread_attr_getstackaddr(const pthread_attr_t *restrict , void **restrict );
   int pthread_attr_setstackaddr(pthread_attr_t *, void *);
   pthread_mutex_init(mutex,attr)
   pthread_mutex_destroy(mutex)
   pthread_mutexattr_init(attr)
   pthread_mutexattr_destroy(attr)
   pthread_mutex_lock()
   pthread_mutex_trylock()
   pthread_mutex_unlock()
   pthread_cond_init()
   pthread_cond_destroy()
   pthread_condattr_init()
   pthread_condattr_destroy()
   pthread_cond_wait(cv,mutex) 
   pthread_cond_signal(cv)
   pthread_cond_broadcast(cv)
   pthread_kill()
   pthread_barrier_wait(&barrier);

   pthread_barrier_t barrier=PTHREAD_BARRIER_INITIALIZER(count);
*/


#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void * thread_handler (void *);
void * signalling_thread(void *);

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cv=PTHREAD_COND_INITIALIZER;
int bcount=4;
//pthread_barrier_t barrier=PTHREAD_BARRIER_INITIALIZER(bcount);

pthread_mutexattr_t mutex_attr;
int count=0;

int main() {

	pthread_t tid[5];
	int index=0;
	void *status=NULL;
	pthread_attr_t attr;
	size_t stack_size;
	int stat;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_attr_getstacksize(&attr,&stack_size);

	printf("Default stack size is %ld bytes \n",stack_size);		
	pthread_attr_setstacksize(&attr,stack_size);

	while (index<4) {
		pthread_create(&tid[index],&attr,thread_handler,(void*)&index);
		index++;
		sleep(1);
		printf("created thread %d\n",index);
	}
	pthread_attr_destroy(&attr);

		pthread_create(&tid[4],NULL,signalling_thread,(void*)&index);

	index=0;
	while (index<5) {
		printf("index is %d \n",index);
		printf("count value is %d \n",count);
		pthread_join(tid[index],&status);
		stat=*((int*)status);
		
/*
 *
 void **status;
 stat=**(int*)status; -> Seg fault invalid memory access 
 
*/
		printf("status returned is %d\n",stat);
		index++;
	}
	printf("exiting main \n");
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
}

void * thread_handler( void * attr) {
	int *a;
	int b=0;
	int c=0;
	void *ptr;	
	a=(int*)attr;
	b=*a;
	printf("a is %p *a is %d\n",a,*a);
	b=b+1;
	usleep(100);
	printf("b is %d \n",b);
	ptr=(void*)&b;
	printf("Thread is -> %d\n",(int)pthread_self());
		c=count;
		pthread_mutex_lock(&mutex);
		printf("mutex locked by thread %d",b);	
//		count++;

		while (count<10) {
        		pthread_cond_wait(&cv,&mutex);
			printf("signalled acked by %d \n",b);	
        	}
#if 0
		if (c>10) {
			printf("signalled by %d \n",b);
			pthread_cond_signal(&cv);
		}
#endif
		printf("mutex unlocked by thread %d \n",b);
		pthread_mutex_unlock(&mutex);
/*
        b- in thread stack space
	so attr is used as it has main task scope
*/
//	pthread_barrier_wait(&barrier);
	pthread_exit(attr);

}


void * signalling_thread(void *arg) {

	while(count<20) {	
	pthread_mutex_lock(&mutex);
	printf("Signalling thread acquired the lock \n");
	count++;
	if (count>10) {
		printf("singalling by signal thread \n");
		pthread_cond_signal(&cv);
	}
		pthread_mutex_unlock(&mutex);
	}
		pthread_exit(arg);
}
