#include "monty.h"

/**
 * get_opcode_func - gets the suitable opcode func based on a given instruction
 * @instruction: instruction to execute
 * @stack: stack
 * @line_number: line number (for error message)
 * Return: nothing.
 */
void get_opcode_func(char *instruction, stack_t **stack,
		unsigned int line_number)
{
	int num_instru, i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
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
	fprintf(stderr, "L%u: unknown instruction  %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
