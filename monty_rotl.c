#include "monty.h"

/**
 * monty_rotl - rotates the top stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	if (!(*stack) || !(*stack)->next)
		return;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp2->prev = NULL;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp1;
	*stack = tmp2;
}
