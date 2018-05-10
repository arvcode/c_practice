/*
int pthread_create(pthread *,const pthread_attr_t *, void * (*)(void *), void *);
void pthread_exit(void *);
int pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
int pthread_cond_init(pthread_cond_t *, const pthread_condattr_t *);

*/

#include<pthread.h>
#include<stdio.h>


void * thread_handler (void *);
int counter=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;


int main() {

	pthread_t tid1, tid2;

	pthread_create(&tid1,NULL,thread_handler,NULL);
	pthread_create(&tid2,NULL,thread_handler,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


}


void * thread_handler(void *p) {
	pthread_mutex_lock(&mutex);
	counter++;
	printf("Thread is %d counter is %d \n",pthread_self(),counter);
	pthread_mutex_unlock(&mutex);



}
