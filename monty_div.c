#include "monty.h"

/**
 * monty_div - divides the top two nodes of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int len, temp;

	tmp = *stack;
	for (len = 0; tmp; len++)
		tmp = tmp->next;
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	temp = tmp->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= temp;
	*stack = tmp->next;
	free(tmp);
}
