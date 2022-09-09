#include "monty.h"

/**
 * call_stack_op - call the apporiate stack_op based on the opcode
 *
 * @head: defines the head of the stack
 * @tokens: array of tokens from line read
 *
 */


void call_stack_op(char **tokens, stack_t **stack)
{
	instruction_t get_op[] = {
		{"push", _push},
		{"pall", _print_dstack},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nod", _nod},
		{NULL, NULL}
	};

	int x = 0;

	/*token = tokenize(op_args);*/

	while (*tokens && get_op[x].opcode)
	{
		printf("%s\n", tokens[1]);
		printf("%d\n", line_number);
		if (strcmp(tokens[0], get_op[x].opcode) == 0)
		{
			printf("%s\n", tokens[1]);
			get_op[x].f(stack, line_number);
			printf("%s\n", tokens[0]);
			break;
		}
		x++;
	}
	if (strcmp(tokens[0], "push") == 0)
	{
		printf("YES\n");
		(*stack)->n = atoi(tokens[1]);
	}

	if (*tokens && get_op[x].opcode == NULL)
	{
		_free_stack(*stack);
		fprintf(stderr, "L%d:instruction not found %s\n", line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
}
