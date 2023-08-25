#include "monty.h"

/**
 * monty_addqueue - adds a node to the end of the queue
 * @stack: pointer to the top of the stack
 * @val: value of new node
 *
 * Return: Nothing
 */
void monty_addqueue(stack_t **stack, int val)
{
	stack_t *new, *tmp;

	tmp = *stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = val;
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	else
	{
		new->prev = NULL;
		*stack = new;
	}
}
