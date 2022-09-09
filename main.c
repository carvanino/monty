#include "monty.h"


/*intialize the global variable for the program */

var_t var = {NULL, NULL};
unsigned int line_number = 0;

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
	char **tokens;
	int byt_read = 1;
	size_t size = 0;
	stack_t *head = NULL; /* defines the head of the pointer */

	/* check that the command line argument is exactly two else error message */
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

	while (byt_read > 0)
	{
		byt_read = getline(&line_read, &size, file);
		if (byt_read > 0)
		{
			var.content = line_read;/* Want to change this to line_read */
			line_number++;
			tokens = tokenize(line_read, " /n/t");
			if (tokens != NULL)
			{
				call_stack_op(tokens, &head);
				free(tokens);
			}
		}
	}
	free(line_read);

	_free_stack(head);
	fclose(file);

	return (0);
}
