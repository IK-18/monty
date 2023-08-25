#include "monty.h"

/**
 * monty_pchar - prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
