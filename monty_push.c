#include "monty.h"

/**
 * monty_push - pushes a new node into list
 * @stack: pointer to top of stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	int val, i = 0;

	if (pseudo.value)
	{
		if (pseudo.value[i] == '-')
			i++;
		while (pseudo.value[i] != '\0')
		{
			if (pseudo.value[i] < 48 || pseudo.value[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(pseudo.file);
				free(pseudo.line);
				monty_free((*stack));
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(pseudo.file);
		free(pseudo.line);
		monty_free((*stack));
		exit(EXIT_FAILURE);
	}
	val = atoi(pseudo.value);
	if (pseudo.order == LIFO)
		monty_addstack(stack, val);
	else
		monty_addqueue(stack, val);
}
