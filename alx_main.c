#include "alx_monty.h"
#include <stdio.h>

global_vars var;

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 f Success, 1 if Failed
 */
int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (start_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	for (var.line_number = 1; getline(&var.buff, &var.tmp, var.file) != EOF; var.line_number++)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (call_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
	}

	free_all();

	return (EXIT_SUCCESS);
}
