//Program to transfer message between two processes using pipes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pro_id; //For using fork() and creating a Child Process
	char buffer[30]; //For storing the string during read()
	int myPipe[2]; //Pipe declaration
	int pipeCheck; //For checking if the pipe is created or not

	pipeCheck = pipe(myPipe); //pipe() returns -1 if an error occurs
	if (pipeCheck == -1)
	{
		perror("pipe"); //perror() is used to display the kind of error occurred
		exit(1);
	}

	pro_id = fork(); //fork() returns -1 if an error occurs
	if (pro_id < 0)
	{
		perror("fork"); //Displaying error
		exit(1);
	}
	else if (pro_id > 0)
	{
		//Parent Process
		printf("This is Parent Process (Reading Message passed by Child Process)\n");
		close(myPipe[1]); //Closing write end of pipe
		read(myPipe[0],buffer,12); //Read the string written in Child Process and store in buffer
		close(myPipe[0]); //Closing read end of pipe
		printf("%s (Displayed in Parent Process)\n",buffer); //Displaying the string passed from the Child Process
	}
	else if (pro_id == 0)
	{
		//Child Process
		printf("This is Child Process (Passing Hello World! to Parent Process)\n");
		close(myPipe[0]); //Closing read end of pipe
		write(myPipe[1],"Hello World!",12); //Hello World! is written to pipe
		close(myPipe[1]); //Closing write end of pipe
	}
	return (0);
}
