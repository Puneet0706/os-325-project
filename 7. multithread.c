//Program to Create two threads, Where one thread prints a welcome message and the other adds two numbers passed by the main process
#include<stdio.h>
#include<pthread.h>

void *welcome(void *arg) //Thread function which prints the Welcome Message
{
	printf("Welcome to Multithreading!\t\t(Printed by First Thread)\n");
}

void *add(void *arg) //Thread function which adds two numbers passed by main process
{
	int *num;
	num = (int *)arg;
	printf("Sum of the Numbers %d and %d is: %d\t(Printed by Second Thread)\n",num[0],num[1],(num[0]+num[1]));
}

int main()
{
	int i;
	int num[2]; //Variable for taking input
	printf("Enter Two Numbers:\n");
	for (i=0;i<2;i++)
	{
		scanf("%d",&num[i]);
	}
	pthread_t thrd1; //Thread for welcome message
	pthread_t thrd2; //Thread for adding two numbers
	pthread_create(&thrd1,NULL,welcome,NULL); //Creating thread for welcome function
	pthread_create(&thrd2,NULL,add,(void *)num); //Creating thread for add function and passing arguments
	pthread_exit(&thrd1); //Exiting thrd1
	pthread_exit(&thrd2); //Exiting thrd2
	return (0);
}
