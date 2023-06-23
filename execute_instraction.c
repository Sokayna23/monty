#include "monty.h"

/**
 * exec_instru - executes instructions based on the given command
 * @instruction: instruction to execute
 * @stack: stack
 * @line_number: number of the line
 */
void exec_instru(stack_t **stack, char *instruction, unsigned int line_number)
{
	int num_instru, i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
	};
	num_instru = sizeof(instructions) / sizeof(instruction_t);
	for (i = 0; i < num_instru; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction  %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
