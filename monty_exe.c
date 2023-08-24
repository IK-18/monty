#include "monty.h"

/**
 * monty_exe - executes the opcode
 * @stack: pointer to top of stack
 * @line_numb: line number
 * @file: pointer to file
 * @line: line content
 *
 * Return: 0 on success, 1 otherwise
 */
int monty_exe(stack_t **stack, unsigned int line_numb, FILE *file, char *line)
{
	instruction_t opcodes[] = {
		{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
		{"pop", monty_pop}, {"swap", monty_swap}, {"add", monty_add},
		{"nop", monty_nop}, {"sub", monty_sub}, {"div", monty_div},
		{"mul", monty_mul}, {"mod", monty_mod}, {"pchar", monty_pchar},
		{"pstr", monty_pstr}, {"rotl", monty_rotl}, {"rotr", monty_rotr},
		{"stack", monty_stack}, {"queue", monty_queue}, {NULL, NULL}
	};
	unsigned int i;
	char *cmd;

	cmd = strtok(line, " \n\t");
	if (cmd && cmd[0] == '#')
		return (EXIT_SUCCESS);
	for (i = 0; opcodes[i].opcode && cmd; i++)
	{
		if (!strcmp(cmd, opcodes[i].opcode))
		{
			opcodes[i].f(stack, line_numb);
			return (EXIT_SUCCESS);
		}
	}
	if (cmd && !opcodes[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_numb, cmd);
		fclose(file);
		free(line);
		monty_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
