#include "monty.h"

/**
 * _add - adds the two top element of the stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
}

/**
 * _nod - Does nothing
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _nod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	(void) stack;
}

/**
 * _sub - adds the two top element of the stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack) = (*stack)->next;
}
