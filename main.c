#include "monty.h"

/**
 * main - process function
 *
 * @args: number of argument
 * @argv: argument vector
 *
 */

int main(int args, char **argv)
{
	char *str = NULL; 
	char *cpy;
	int byt_read;
	size_t size;

	byt_read = getline(&str, &size, stdin);

	if (byt_read == -1)
	{
		printf("error");
	}
	else
	{
		printf("%s\n", str);
	}
}
