#include "monty.h"

/**
 * get_opcode_func - gets the suitable opcode func based on a given instruction
 * @instruction: instruction to execute
 * Return: a pointer to afunction
 */
void (*get_opcode_func(char *instruction))(stack_t **, unsigned int)
{
	int num_instru, i;
	unsigned int line_number = 1;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	num_instru = sizeof(instructions) / sizeof(instruction_t);
	for (i = 0; i < num_instru; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
		{
			line_number++;
			return (instructions[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction  %s\n", line_number, instruction);
	data.status = EXIT_FAILURE;
	exit(data.status);
}
