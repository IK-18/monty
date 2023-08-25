#include "monty.h"

/**
 * monty_rotr - rotates the bottom stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp1, *tmp2;

	if (!(*stack) || !(*stack)->next)
		return;
	tmp1 = *stack;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->prev;
	tmp1->next = *stack;
	tmp1->prev = NULL;
	tmp2->next = NULL;
	(*stack)->prev = tmp1;
	*stack = tmp1;
}
