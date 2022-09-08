#include "monty.h"


/*intialize the global variable for the program */

var_t var = {NULL, NULL};

/**
 * main - process function
 *
 * @args: number of argument
 * @argv: argument vector
 *
 */

int main(int argc, char *argv[])
{
	char *op_args;
	FILE *file;
	int byt_read = 1;
	size_t size;
	stack_t *head = NULL /* defines the head of the pointer */
	unsigned int counter = 0;

	/* check from that the command line argument is exactly two else error message */
	if (argc !=2 ){
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file){
		fprintf(stderr, "Fatal Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	var.file = file;

	while (byt_read > 0)
	{
		op_args = NULL;
		byt_read = getline(&op_args, &size, file);
		var.content = op_args;
		counter++;

		if (byt_read > 0){
			/*TODO: function to tokenizer aand pas to variadic for the opcode instructions */
			print("%s\n", op_args[1]);
		}
		free(op_args);
	}
	_free_stack(head);
	fclose(file);
}
