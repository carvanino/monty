#include "monty.h"

/*
 * _free_stack - frees the doubly list struct
 * @head: defines the heaad of the stack
 *
 */

void _free_stack(stack_t *stack)
{
	stack_t *temp;
	temp = stack;
	while(stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
