#include "monty.h"

var_t var;

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
	/*printf("HERE\n");*/
	if (newnode == NULL) /* if no argument is given to push */
	{
		fprintf(stderr, "L%d: usage: push op integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*printf("HERE21\n");*/
	/*printf("%d\n", atoi(var.tokens[1]));*/
	(newnode)->n = atoi(var.tokens[1]);
	/*printf("HERE2\n");*/
	newnode->prev = NULL;
	newnode->next = NULL;
	if ((*stack) ==  NULL)
	{
		*stack = newnode;
	}
	else
	{
		/*printf("HERE");*/
		(*stack)->prev = newnode;
		newnode->next = *stack;
		newnode->prev = NULL;
	}
	*stack = newnode;
}

/**
 * _print_dstack - prints all the values on the stack from the top
 *
 * @stack: pointer to the list
 *
 */

void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *transv;


	if ((*stack) == NULL)
	{
		return;
	}
	transv = *stack;
	while (transv != NULL)
	{
		fprintf(stdout, "%d\n", transv->n);
		/*printf("PALL\n");*/
		/*fprintf(stdout, "%x\n", transv->next);*/
		transv = transv->next;
	}
	/*fprintf(stdout, "%d\n", transv->n);*/
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
		*stack = NULL;
	}
	else
	{
		transv = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		transv->next = NULL;
		free(transv);
	}
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
