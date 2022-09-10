#ifndef MONTY_H
#define MONTY_H

#define __GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define __GNU_SOURCE

extern unsigned int line_number;

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
	char **tokens;
} var_t;


void _free_stack(stack_t *stack);
void _push(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _pint(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _pop(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _swap(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _add(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _nod(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _sub(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _div(stack_t **stack, __attribute__((unused)) unsigned int line_number);


void call_stack_op(char **tokens, stack_t **stack);
int no_toks(char *str, char *delim);
char **tokenize(char *str, char *delim);

#endif /* MONTY_H */
