#include "monty.h"


/**
 * _pchar - prints the top character
 * @stack: define the head of the stack
 * @line_number: the line counter
 * Return: void
 */
void _pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = (*stack);

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*check that the character is between the ascii character range*/
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	}
	printf("%c\n", tmp->n);
}
