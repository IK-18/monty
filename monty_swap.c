#include "monty.h"

/**
 * monty_swap - swaps the top two nodes of the stack
 * @stack: pointer to top of stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int len, temp;

	tmp = *stack;
	for (len = 0; tmp; len++)
		tmp = tmp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

