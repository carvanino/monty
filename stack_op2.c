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
		fprintf(stderr, "L%d: can't add, stack empty\n", line_number);
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
 * _sub - subtracts the two top element of the stack and
 * replaces the second top element with the result of the subtraction
 * and remove the top element
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack) = (*stack)->next;
}


/**
 * _div - divides the second elemnt of the stack by the top element
 * the result is stored in the second top element and the top element removed
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _div(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
}


/**
 * _mul - multiplies the two top element of the stack and
 * replaces the second top element with the result of the multiplication
 * and remove the top element
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _mul(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	(*stack) = (*stack)->next;
}
