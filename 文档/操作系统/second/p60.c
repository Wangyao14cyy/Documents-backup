#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
	printf("Hello world!\n");
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
	pthread_t thread[NUMBER_OF_THREADS];
	int statue,i;
	for (i = 0; i<NUMBER_OF_THREADS; ++i)
	{
		printf("Main here .Creating thread %d\n",i);
		statue=pthread_create(&thread[i],NULL,print_hello_world,(void *)i);
		if(statue!=0)		   
	 		{
			printf("Oops.pthread_create return error code %d\n",statue);//success or fail
			exit(-1);
			}
	}
	exit(NULL);
}
