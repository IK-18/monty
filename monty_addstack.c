#include "monty.h"

/**
 * monty_addstack - adds a node to the top of the stack
 * @stack: pointer to the top of the stack
 * @val: value of new node
 *
 * Return: Nothing
 */
void monty_addstack(stack_t **stack, int val)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = val;
	if ((*stack))
		(*stack)->prev = new;
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
}
