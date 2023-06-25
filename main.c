#include "monty.h"

monty_data_t data = {NULL, 0, 0, 1};

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
	data.is_stack = 1;
	data.input_value = NULL;
	while (getline(&buffer, &buf_size, file) != -1)
	{
		data.line_number++;
		if (*buffer == '\n')
			continue;
		instruction = strtok(buffer, " \t\n");
		if (instruction == NULL || instruction[0] == '#')
			continue;
		data.input_value = strtok(NULL, " \t\n");
		get_opcode_func(instruction)(&stack, data.line_number);
	}
	free(buffer);
	free_stack(&stack);
	fclose(file);
	exit(data.status);
}
