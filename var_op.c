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
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"nod", _nod},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"rotl", _rotl},
		{NULL, NULL}
	};

	int x = 0;


	while (get_op[x].opcode)
	{
		/*printf("%s\n", tokens[x]);*/
		/*printf("Line number: %d\n", line_number);*/
		if (tokens[0][0] == '#')
		{
			return;
		}
		if (strcmp(tokens[0], get_op[x].opcode) == 0)
		{
			if (get_op[x].f)
			{
				/*printf("%s\n", get_op[x].opcode);*/
				get_op[x].f(stack, line_number);
			}
			printf("%s\n", tokens[0]);
			break;
		}
		/*printf("%s\n", tokens[0]);*/
		x++;
	}

	if (get_op[x].opcode == NULL)
	{
		_free_stack(*stack);
		fprintf(stderr, "L%d:instruction not found %s\n", line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
}
