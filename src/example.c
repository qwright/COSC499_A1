#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "example.h"


int main(int argc, char *argv[])
{
	int a = -1;
	int b = -1;
	int ans = -1;
	int opt;
	while((opt = getopt(argc, argv, "m:")) != -1){
	switch(opt){
		case 'm':
			if(strcmp(optarg, "sum") == 0){
				prompt(&a, &b);
				ans = sum(a,b);
				printf("Result: %d\n", ans);
			}
			else if(strcmp(optarg, "sub") == 0){
				prompt(&a, &b);
				ans = subtract(a,b);
				printf("Result: %d\n", ans);
			}
			else{
				usage();
			}
			break;
		default:
			usage();
			return 1;
		}
	}
	return 0;
}

int sum(int num1, int num2)
{
	return num1 + num2;
}

int subtract(int num1, int num2)
{
	return num1 - num2;
}

void usage(void)
{
	printf("Usage:\n");
	printf("-<mode>\n");
	printf("Modes available: sum, sub\n");
}

void prompt(int *n1, int *n2)
{
	printf("This is some toy code for Capstone\n");
	printf("Enter first number:\n");
	scanf("%d", n1);
	printf("Enter second number:\n");
	scanf("%d", n2);

}
