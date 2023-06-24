#include "monty.h"

/**
 * get_opcode_func - gets the suitable opcode function
 * based on the given instruction
 * @instruction: instruction to execute
 * @line_number: line number
 * Return: a pointer function
 */
void (*get_opcode_func(char *instruction))(stack_t **, unsigned int)
{
	unsigned int line_number = 1;
	int num_instru, i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nop},
		{"pint", pint},
		{NULL, NULL}
	};

	num_instru = sizeof(instructions) / sizeof(instruction_t);
	for (i = 0; i < num_instru; i++)
	{
		if (strcmp(instruction, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
		line_number++;
	}
	fprintf(stderr, "L%d: unknown instruction  %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
