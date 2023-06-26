#include "monty.h"

monty_data_t data = {NULL, 0, 0};

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
	char *buffer = NULL, *instruction = NULL;
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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	data.input_value = NULL;
	while (getline(&buffer, &buf_size, file) != -1)
	{
		if (*buffer == '\n')
		{
			line_number++;
			continue;
		}
		instruction = strtok(buffer, " \t\n");
		if (instruction == NULL)
		{
			line_number++;
			continue;
		}
		data.input_value = strtok(NULL, " \t\n");
		get_opcode_func(instruction, &stack, line_number);
		line_number++;
	}
	free(buffer);
	free_stack(&stack);
	fclose(file);
	exit(data.status);
	return (0);
}
