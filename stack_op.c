#include "monty.h"

/**
 * _push - adds a node to the top of the list
 *
 * @stack: A pointer to the list
 * @line_number: Line number(integerto be added to stack)
 */

void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	printf("HERE");
	if (newnode == NULL || (*stack) == NULL) /* if no argument is given to push */
	{
		fprintf(stderr, "L%d: usage: push op integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* TODO: Get line number*/
	(*stack)->n = line_number;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*stack ==  NULL)
	{
		*stack = newnode;
	}
	else
	{
		printf("%d", (*stack)->n);
		printf("HERE");
		(*stack)->prev = newnode;
		newnode->next = *stack;
		newnode->prev = NULL;
	}
}

/**
 * _print_dstack - prints all the values on the stack from the top
 *
 * @stack: pointer to the list
 *
 */

void _print_dstack(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *transv;

	transv = *stack;
	while (transv != NULL)
	{
		fprintf(stdout, "%d\n", transv->n);
		transv = transv->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element on a stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *transv;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
	}
	transv = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	transv->next = NULL;
	free(transv);
}

/**
 * _swap - swaps the top two element in the stack
 *
 * @stack: pointe to the start of the stack
 * @line_number: Line number
 *
 */

void _swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int swap;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = swap;
}
