// Victor Cano
// Garret Poppe
// CSC 341
// 09-17-2024

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; /*This data is shared by the thread(s) */
void *runner(void *param); /* Threads call this function */

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	/*create the thread */
	pthread_create(&tid, &attr, runner, argv[1]);

	/*wait for the thread to exit */
	pthread_join(tid, NULL);
	printf("sum = %d \n",sum);
}

void *runner(void *param)
{
	int i, upper = atoi(param);
	sum = 0;

	for(i = 1; i <= upper; i++)
	{
		sum += i;
	}

	printf("Enter a number \n");
	int x = 8;
	scanf("%d",x);

	pthread_exit(0);
}
