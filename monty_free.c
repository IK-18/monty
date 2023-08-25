#include "monty.h"

/**
 * monty_free - frees the stack
 * @stack: pointer to stack
 *
 * Return: Nothing
 */
void monty_free(stack_t *stack)
{
	stack_t *tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
