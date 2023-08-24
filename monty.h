#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define LIFO 0
#define FIFO 1

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
 * struct pseudo_s - pseudo variables for functions
 * @value: value being passed into function
 * @file: pointer to monty file
 * @line: content of line
 * @order: order of stack
 */
typedef struct pseudo_s
{
	char *value;
	FILE *file;
	char *line;
	int order;
} pseudo_t;

extern pseudo_t pseudo;

void monty_add(stack_t **stack, unsigned int line_number);
void monty_addqueue(stack_t **stack, int val);
void monty_addstack(stack_t **stack, int val);
void monty_div(stack_t **stack, unsigned int line_number);
int monty_exe(stack_t **stack, unsigned int line_numb, FILE *file, char *line);
void monty_free(stack_t *stack);
void monty_mod(stack_t **stcak, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stcak, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stcak, unsigned int line_number);

#endif /* MONTY_H */
