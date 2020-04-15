//Program to avoid Race Condition using Mutex locks
#include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mtx; //Global Mutex declaration

void *countFun(void *args) //Function for counting numbers upto 100000
{
	while (count < 100000)
	{
		pthread_mutex_lock(&mtx); //Locking the Critical Section using Mutex
		count++; //Critical Section 
		pthread_mutex_unlock(&mtx); //Unlocking the Critical Section using Mutex
		printf("%d\t",count); //Printing Count
	}
}

int main()
{
	int i;
	pthread_t thrd[4]; //Declaration of 4 threads
	for (i=0;i<4;i++)
	{
		pthread_create(&thrd[i],NULL,countFun,NULL); //Creation of 4 threads
	}
	for (i=0;i<4;i++)
	{
		pthread_exit(&thrd[i]); //Exiting each thread
	}
	return (0);
}

//You won't see the difference simply by running the program, to see the difference, after compiling it with: gcc Mutex.c -lpthread
//Enter the command: ./a.out | wc -w
//This command will return the word count of the words printed, it should be 100000 because we are counting till 100000
//But if we comment the lines of mutex locks (pthread_mutex), and run using same commands after compiling
//Then you will see that the word count is different everytime and not 100000, because multiple threads are accessing Critical Section at the same time
