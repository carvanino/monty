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
/**
 * _pstr - prints the top string
 * @stack: define the head of the stack
 * @line_number: the line counter
 * Return: void
 */
void _pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = (*stack);

	while (tmp != NULL)
	{
		if (tmp->n > 127 || tmp->n <= 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * _rotr - prints the top string
 * @stack: define the head of the stack
 * @line_number: the line counter
 * Return: void
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = (*stack);

	if (tmp == NULL || tmp->next == NULL)
	{
		return;
	}

	while (tmp)
	{
		tmp = tmp->next;
	}

	tmp->next = (*stack);
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
