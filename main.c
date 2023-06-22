#include "monty.h"

/**
 * main - Monty interpreter
 * @argc: arguments counter
 * @argv: aarguments passed to the program
 * Return: Alwqys 0.
 */
int main(int argc, char **argv)
{
	FILE *file;
	stack_t *stack = NULL;
	char *buffer = NULL, *args;
	size_t buf_size = 0;
	unsigned int line_number = 1;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file \n",);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buf_size, file) != -1)
	{
		if (*buffer == '\n')
		{
			line_number += 1;
			continue;
		}
		args = strtok(buffer, " \t\n");
		if (args == NULL)
		{
			line_number += 1;
			continue;
		}
		args = strtok(NULL, " \t\n");
		exec_instru(stack, args, line_number);
		line_number++;
	}
	free(buffer);
	free_stack(stack);
	fclose(file);
	exit(0);
}
