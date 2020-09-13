#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "example.h"
#include "test_example.h"


int main(int argc, char *argv[])
{
	int a = -1;
	int b = -1;
	int ans = -1;
	int opt;
	while((opt = getopt(argc, argv, "m:t")) != -1){
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
		case 't':
			test_example();
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
	printf("-m <mode>\n");
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

void test_example(void)
{
	printf("testing sum:\n");
	if(sum(0,0)==0){
		printf("Test 1: Pass\n");
	}else{
		printf("Test 1: Fail\n");
	}
	if(sum(0,1)==1){
		printf("Test 2: Pass\n");
	}else{
		printf("Test 2: Fail\n");
	}
	if(sum(-1,1)==0){
		printf("Test 3: Pass\n");
	}else{
		printf("Test 3: Fail\n");
	}
	printf("testing sub:\n");
	if(subtract(0,0)==0){
		printf("Test 1: Pass\n");
	}else{
		printf("Test 1: Fail\n");
	}
	if(subtract(1,0)==1){
		printf("Test 2: Pass\n");
	}else{
		printf("Test 2: Fail\n");
	}
	if(subtract(-1,1)== -2){
		printf("Test 3: Pass\n");
	}else{
		printf("Test 3: Fail\n");
	}
}
