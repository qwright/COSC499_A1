#include <stdio.h>
#include "example.h"

int main()
{
	printf("This is some toy code for Capstone\n");
	int a = 3;
	int b = 2;
	int s = sum(a,b);
	printf("Sum of %d and %d : %d\n",a,b, s);

	return 0;
}

int sum(int num1, int num2)
{
	return num1 + num2;
}
