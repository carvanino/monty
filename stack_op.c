#include "monty.h"

/**
 * _push - adds a node to the top of the list
 *
 * @stack: A pointer to the list
 * @line_number: Line number(integerto be added to stack)
 */

void _push(struct_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL || (*stack) == NULL) /* if no argument is given to push */
        {
                fprintf(2, "L<line_number>: usage: push integer\n"), ;
		exit(EXIT_FAILURE);
	}
	/* TODO: Get line number */
	newnode->n = line_number;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*stack ==  NULL)
	{
		*stack = newnode;
	}
	else
	{
		(*stack)->prev = newnode;
		newnode->next = *stack;
		newnode->prev = NULL;
	}
}

/**
 * _print_dstack - prints all the values on the stack from the top
 *
 * @stack: pointer to the list
 * @line_number: Line number
 *
 */

void _print_dstack(stack_t **stack)
{
	stack_t *transv;

	transv = *stack;
	while (transv != NULL)
	{
		fprintf(1, "%d\n", transv->n);
		transv = transv->next;
	}
}

TODO: pop opcode
/**
 * _pop - prints the value at the top of the stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

void _pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(2, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	fprintf(1,"%d\n", (*stack)->n);
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


	if (*stack == NULL || *stack->next == NULL)
	{
		fprintf(2, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
		 
	}
	swap = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack->n) = swap;
}

/**
 * _add - adds the two top element of the stack
 *
 * @stack: pointer to the start of the stack
 * @line_number: Line number
 *
 */

stackt_t _add(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(2, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	return((*stack)->next->n);
}


