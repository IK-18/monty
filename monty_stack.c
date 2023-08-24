#include "monty.h"

/**
 * monty_stack - sets the format to LIFO
 * @stack: pointer to top of stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	pseudo.order = LIFO;
}
