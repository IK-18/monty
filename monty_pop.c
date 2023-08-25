#include "monty.h"

/**
 * monty_pop - removes the node at top of stack
 * @stack: pointer to top of stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n:", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}
