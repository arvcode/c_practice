#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_cond  = PTHREAD_COND_INITIALIZER;

void *functionCount1();
void *functionCount2();
int  count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6

main()
{
   pthread_t thread1, thread2;

   pthread_create( &thread1, NULL, &functionCount1, NULL);
   pthread_create( &thread2, NULL, &functionCount2, NULL);
   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   exit(0);
}

void *functionCount1()
{
   for(;;)
   {
      pthread_mutex_lock( &condition_mutex );
	printf("thread 1 got the lock \n");
      while( count >= 3 && count <= 6 )
      {
  	 printf("waiting here \n");
         pthread_cond_wait( &condition_cond, &condition_mutex );
      }
      pthread_mutex_unlock( &condition_mutex );
	printf("thread 1 unlocked \n");
      pthread_mutex_lock( &count_mutex );
	printf("thread 1 locked count mutex \n");
      count++;
      printf("Counter value functionCount1: %d\n",count);
      pthread_mutex_unlock( &count_mutex );

      if(count >= 10) return(NULL);
    }
}

void *functionCount2()
{
    for(;;)
    {
       pthread_mutex_lock( &condition_mutex );
	printf("thread 2 got the lock \n");
       if( count < 3 || count > 6 )
       {
	  printf("signal at count %d \n",count);
          pthread_cond_signal( &condition_cond );
       }
       pthread_mutex_unlock( &condition_mutex );
	printf("thread 2 unlocked \n");
	
       pthread_mutex_lock( &count_mutex );
	printf("thread 2 locked count mutex \n");
       count++;
       printf("Counter value functionCount2: %d\n",count);
       pthread_mutex_unlock( &count_mutex );

       if(count >= 10 return(NULL);
    }

}
