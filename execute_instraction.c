#include "monty.h"

/**
 * get_opcode_func - gets the suitable opcode function based on the given instruction
 * @instruction: instruction to execute
 */
void (*get_opcode_func(char *instruction, unsigned int line_number))(stack_t **, unsigned int)
{
	int num_instru, i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	num_instru = sizeof(instructions) / sizeof(instruction_t);
	for (i = 0; i < num_instru; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction  %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
