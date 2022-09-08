#include "monty.h";

/*
 * _free_stack - frees the doubly list struct
 * @head: defines the heaad of the stack
 *
 */

void _free_stack(stack_t *head)
{
	stack_t temp;
	temp = head;
	while(head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
