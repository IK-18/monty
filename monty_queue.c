#include "monty.h"

/**
 * monty_queue - sets the format to FIFO
 * @stack: pointer to top of stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	pseudo.order = FIFO;
}
