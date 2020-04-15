//Program to implement Banker's Algorithm for p processes and 2 resources having 2 instances per resource
#include <stdio.h>

int main()
{
	int i,j,p,r=2; //Number of Processes is p and Number of Resources is r
	int avail[2] = {2,2}; //Available instances of both resources
	printf("Enter the Number of Processes: ");
	scanf("%d",&p); //For taking number of resources as input
	int alloc[p][2]; //Allocation matrix
	int max[p][2];  //Maximum matrix
	int need[p][2]; //Need matrix
	//Taking input for allocation matrix
	for ( i = 0 ; i < p ; i++ )
	{
		for ( j = 0 ; j < r ; j++ )
		{
			printf("For Process %d, Enter the initially allocated instances of Resource %d: ",(i+1),(j+1));
			scanf("%d",&alloc[i][j]);
		}
	}
	//Changing available instances as per allocation matrix
	for ( i = 0 ; i < p ; i++)
	{
		for ( j = 0 ; j < r ; j++)
		{
			avail[j] = avail[j] - alloc[i][j];
		}
	}
	//Taking input for Maximum matrix
	for ( i = 0 ; i < p ; i++ )
	{
		for ( j = 0 ; j < r ; j++ )
		{
			printf("For Process %d, Enter the maximum allocation of instances of Resource %d: ",(i+1),(j+1));
			scanf("%d",&max[i][j]);
		}
	}
	//Calculating Need matrix
	for ( i = 0 ; i < p ; i++ )
	{
		for ( j = 0 ; j < r ; j++ )
		{need[i][j] = (max[i][j]) - (alloc[i][j]);}
	}
	int isAvail; //For checking both the conditions for resource instance allocation are satisfied or not
	int isSafe = 1;	//For checking system is safe or not
	int finish[p]; //For checking processes are finished or not
	//Initializing the finish array
	for ( i = 0 ; i < p ; i++)
	{finish[i] = 0;}
	int pass; //Number of passes required is equal to number of processes
	int index = 0, safeSequence[p];	//For printing safe sequence
	//Code for Safe State and Safe Sequence
	for ( pass = 0 ; pass < p ; pass++)
	{
		for ( i = 0 ; i < p ; i++ )
		{
			if ( finish[i] == 0 )
			{
				isAvail = 1;
				for ( j = 0 ; j < r ; j++ )
				{
					if ( need[i][j] > avail[j] )
					{isAvail = 0;}
				}
				if ( isAvail == 1 )
				{
					safeSequence[index++] = i;
					for ( j = 0 ; j < r ; j++ )
					{avail[j] = avail[j] + alloc[i][j];}
					finish[i] = 1;
				}
			}
		}
	}
	//Code for printing that the system is in Safe State or not and if yes then printing the Safe Sequence
	for ( i = 0 ; i < p ; i++ )
	{
		if ( finish[i] == 0)
		{isSafe = 0;}
	}
	if ( isSafe == 1 )
	{
		printf("The System is in Safe State and the Safe Sequence is:");
		for ( i = 0 ; i < (p-1) ; i++)
		{printf(" P%d ->",safeSequence[i]);}
		printf(" P%d\n",safeSequence[p-1]);
	}
	else
	{printf("The System is not in Safe State\n");}
}
