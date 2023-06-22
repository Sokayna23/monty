#include "monty.h"

/**
 * exec_instru - executes instructions based on the given command
 * @instruction: instruction to execute
 * @stack: stack
 * @line_number: number of the line
 */
void exec_instru(char *instruction, stack_t **stack, unsigned int line_number)
{
	int num_instru, i;
	instruction_t instructions[] = {
		{"push", &push},
		{"pall", &pall},
	};
	num_instru = sizeof(instructions) / sizeof(instruction_t);
	void (*instruction_func)(stack_t **, unsigned int) = NULL;
	for (i = 0; i < num_instru; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
		{
			instruction_func = instructions[i].f;
			break;
		}
	}
	if (instruction_func == NULL)
	{
		fprintf(stderr, "Error: Unsupported instruction: %s\n", instruction);
		exit(EXIT_FAILURE);
	}
	instruction_func(stack, line_number);
}
