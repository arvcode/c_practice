#include<stdio.h>
#include<pthread.h>

#define TMAX 100

FILE *fp=NULL;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t	cv[TMAX]=PTHREAD_COND_INITIALIZER;

void * thread_reader (void *);
void * signal_thread(void*);
int count=0;
int flag=0;
int start_flag=0;
int main () {

	pthread_t tid[TMAX];
	int targ[TMAX];
	int numt=0;
	int index=0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	fp=fopen("file.txt","r");
	
	printf("Enter the number of threads \n");
	
	scanf("%d",&numt);
	if (numt>TMAX) {
		printf("Number of threads exceeded \n");
	}
	start_flag=numt;
	while (index<numt) {
		targ[index]=index;
		pthread_create(&tid[index],NULL,thread_reader,(void*)&targ[index]);
		index++;
		usleep(1);
	}


	index=0;
	while (index<numt) {
		pthread_join(tid[index],NULL);
		index++;
	}
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);

}

void * thread_reader (void *arg) {
	int *index;
	char c=0;
	index=(int *)arg;
	while (1) {
		pthread_mutex_lock(&mutex);
		while (count!=*index) {
			pthread_cond_wait(&cv[*index],&mutex);
		}
	        printf("\nthread is %d count is %d \n",*index,count);	
		while(flag!=1 && (c=fgetc(fp))!=EOF) {
			if (c!=' ' &&  c!='\n' && c!='\t') {
				printf("[%c]",c);	
			} else {	
				printf("[%c]",c);
				break;
			}
		}
		if (c==EOF) {
			flag=1;
		}
		count++;
		if (count==start_flag){
			count=0;
		}
		pthread_cond_signal(&cv[count]);
		if (flag==1) {
			break;
		}
		pthread_mutex_unlock(&mutex);
	}

	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

void * signal_thread(void *arg) {
	int *numt=(int*)arg;
	while (1) {
		pthread_mutex_lock(&mutex);
		start_flag++;
		count++;
		if (start_flag>=*numt) {
			start_flag=0;
			count=0;
		}
		pthread_cond_signal(&cv[start_flag-1]);
#if 0
//		printf("signal thread got the lock count is %d %d \n",count,*numt);
		if(count>=*numt) {
			count=0;
//			printf("sending signal \n");
			pthread_cond_signal(&cv);
		} else {
			count++;
			pthread_cond_signal(&cv);			
		}
#endif
		pthread_mutex_unlock(&mutex);
		if (flag==1) break;
	}
	pthread_exit(NULL);
}
