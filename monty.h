#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_t - defines the struct to save the file $ content
 * @file: a pointer to monty file
 * @content: defines the content from command line arguments
 * Description: carries the values of the program
 */

typedef struct var_s 
{
	FILE *file;
	char *content;
} var_t;

void _free_stack(stack_t *stack);
void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _print_dstack(stack_t **stack);
void _pint(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _pop(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _swap(stack_t **stack, __attribute__((unused)) unsigned int line_number);
stack_t _add(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _nod(stack_t **stack, --attribute__((unused)) unsigned int line_number);


int stack_op(char *op_args, stack_t *stack, unsigned int line_number);
int no_toks(char *str, char *delim);
char **tokenize(char *str, char *delim)

#endif /* MONTY_H */
