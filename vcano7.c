// Victor Cano
// Garret Poppe
// CSC 341
// 10-01-2024

#include <stdio.h>
#include <stdlib.h>

int compare_and_swap(int *pointb, int expected, int new_value);

void values_to_swap(int *pointa, int *pointb, int *pointc, int *pointd);

int main(void)
{
	/*using pointers is helpful when you want to permanantely set the value of a variable
	* using functions. Normally when variables are created or modified in
	* functions they disapear
	* after the function completes, with pointers you are changing a value by
	using it's address.
	*/
	int *pointa;
	int expected = 9;
	int newValue = 45;
	int valueOne = 7;
	int valueTwo =77;

	//A pointer only points to the address space of another value
	pointa = &expected;
	//pointa now points to the address space of the value expected.

	//it only stores addresses.
	printf(" address stored in pointa is %p \n",pointa);
	
	//if we want to see if that address is the same as the variable expected
	printf(" address of variable named expected is %p \n",&expected);
	
	//these print statment print the same thing because we set our pointer to point to expected
	//If we want to see the value that the pointer is pointing to,
	//we use the * before our pointer
	printf(" value that pointa points to is %d \n",*pointa);
	
	//this should be the the same as the value of expected
	printf(" value of expected is %d \n",expected);
	
	//when we call a separate function we may need to pass it variables
	//this function requires three variable to be passed to it
	//it also returns a value to we need to save that value after the function completes
	int valueReturned = compare_and_swap(pointa,expected,newValue);
	
	//after the function completes it should have swapped expected with new value
	printf("expected = %d, old value which was returned is %d \n",expected,valueReturned);
	
	printf("These are the values we have before swapping them aroound: \n");
	printf("\nValue One = %d\nValue Two = %d\n\n", valueOne, valueTwo);

	values_to_swap(&valueReturned, &expected, &valueOne, &valueTwo);

	printf("We will first swap the Expected again:\n");
	printf("Expected = %d, old value which was returned is %d\n",expected,valueReturned);
	printf("These are the new values after being swapped:\nValue one: %d, Value two: %d\n", valueOne, valueTwo);


	return EXIT_SUCCESS;
}

int compare_and_swap(int *pointb, int expected, int new_value)
{
	//we can use the same name for expected and it will be a different variable in this function
	int temp = *pointb;
	//created a temp variable to store the original value located at the pointer pointb

	if(*pointb == expected)
	{
		*pointb = new_value;
	}

	return temp;
}

void values_to_swap(int *pointa, int *pointb, int *pointc, int *pointd)
{
	int temp;

	temp = *pointa;
	*pointa = *pointb;
	*pointb = temp;

	temp = *pointc;
	*pointc = *pointd;
	*pointd = temp;
}
