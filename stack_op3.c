#include "monty.h"

/**
 * _mod - get the modulus of the second elemnt of the stack and the top element
 * the result is stored in the second top element and the top element removed
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _mod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	(*stack) = (*stack)->next;
}

/**
 * _rot1 - rototes the the stack to the top but keeps the bottom element of the
 * stack as the bottom
 *
 * @stack - pointer to start of the stack
 * @line_number: line number
 *
 */

void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *transv, *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	transv = *stack;
	temp = transv->next;
	while (transv->next != NULL)
	{
		transv = transv->next;
	}
	transv->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = transv;
	(*stack)->next = NULL;
	(*stack) = temp;
}

