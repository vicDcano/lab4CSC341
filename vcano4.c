//Victor Cano
//CSC-341
////Sample Pointer Program

#include <stdio.h>
#include <stdlib.h>

//intialize values
int x;
int y =15;

int main(int argc, char *argv[])
{

	//local variables which hold values
	int i; // stack Variable
	int z = 0;
	int *values; //Stack data
	
	//Heap variable
	values = (int*)malloc(sizeof(int) * 5);
	
	printf("Local variable i in stack address is %p\n", &i);
	printf("Heap malloc address is %p \n",values);
	printf("Unitialized x variable Address: %p\n", &x);
	printf("Intialized y variable Address: %p\n", &y);

	return EXIT_SUCCESS;
}
