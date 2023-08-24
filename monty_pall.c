#include "monty.h"

/**
 * monty_pall - prints all the values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: Nohting
 */
void monty_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
		return;
	for (tmp = *stack; tmp->next; tmp = tmp->next)
		printf("%d\n", tmp->n);
}
