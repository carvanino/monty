#include "monty.h"

/*
 * call_stacK_op - call the appropraite stack_op based on the opcode
 * @head: defines the head of the stack
 * @counter: defines the line counter
 * Return: 0 on sucess else 1 on failure
 */


int call_stack_op(char* op_args, stack_t **head, unsigned int counter)
{
	instruction_t get_op[] = {
		{"push", _push},
		{"pall", _print_dstack},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"_nod", nod},
		{NULL, NULL}
	};

	int x = 0;
	char **token;

	token = tokenize(op_args);

	while (tok_op && get_op[x].opcode)
	{
		/* check to compair if the opcode matches the bytcode instruction opcode*/
		if(strcmp(token[0], get_op[x].opcode) == 0)
		{
			get_op[x].f(head, counter);
			return 0;
		}
		x++;
	}
	/* check for a scenario where  */
	if(tok_op && ops[x].opcode = NULL) /* Not sue if this is needed*/
	{
		free(op_args);
		_free_stack(*head);
		fprintf(stderr, "L%d:instruction not found %s\n", counter, tok_op)
		exit(EXIT_FAILURE);
	}
	return 1;
}
