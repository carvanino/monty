#include "monty.h"


/*intialize the global variable for the program */

var_t var = {NULL, NULL};

/**
 * main - process function
 *
 * @argc: number of argument
 * @argv: argument vector
 *
 */

int main(int argc, char **argv)
{
	char *line_read = NULL;
	FILE *file;
	char *tokens = NULL;
	int byt_read = 1;
	size_t size;
	stack_t *head = NULL /* defines the head of the pointer */
	unsigned int counter = 0;

	/* check from that the command line argument is exactly two else error message */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Fatal Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	var.file = file;

	
	while (byt_read = getline(&line_read, &size, file) != -1)
	{
		var.content = line_read;/* Want to change this to line_read */
		counter++;

		if (byt_read > 0) /* Condition not necessary */
		{
			/*TODO: function to tokenizer aand pas to variadic for the opcode instructions */
			printf("%s\n", str[1]);
		}
		free(line_read);
	}
	_free_stack(head);
	fclose(file);
}
