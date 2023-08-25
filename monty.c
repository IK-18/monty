#include "monty.h"
pseudo_t pseudo = {NULL, NULL, NULL, 0};

/**
 * main - main function
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: 0 on success, 1 otherwise
 */
int main(int ac, char **av)
{
	char *line;
	FILE *file;
	size_t size = 0;
	ssize_t rbytes = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (rbytes = 1; rbytes > 0; )
	{
		line = NULL;
		rbytes = getline(&line, &size, file);
		pseudo.line = line;
		line_number++;
		if (rbytes > 0)
			monty_exe(&stack, line_number, file, line);
		free(line);
	}
	monty_free(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
