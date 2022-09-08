#include "monty.h"

/*
 * stack_op - a switch founder for opcode operation
 * @head: defines the head of the stack
 * @counter: defines the line counter
 * Return: 0 on sucess else 1 on failure
 */


int stack_op(char* op_args, stack_t **head, unsigned int counter)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pop", _pop},
		{"swap", _swap},
		{NULL, NULL}
	};


	unsigned int x = 0;
	char *tok_op;

	tok_op = strtok(op_args, " \n\t");

	while (tok_op && ops[x].opcode )
	{
		/*a check to compair if the opcode matches the bytcode instruction opcode*/
		if(strcmp(tok_op, ops[x].opcode) == 0)
		{
			/* a call to the respective stack operation function */
			ops[x].f(head, counter);
			return 0;
		}
		x++;
	}
	/* check for a scenario where the  */
	if(tok_op && ops[x].opcode = NULL)
	{
		free(op_args);
		_free_stack(*head);
		fprintf(stderr, "L%d:instruction not found %s\n", counter, tok_op)
		exit(EXIT_FAILURE);
	}
	return 1;
}
