#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: number of lines
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	char *value = data.input_value;

	if (value == NULL || value[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i]; i++)
	{
		if (!((value[i] >= '0' && value[i] <= '9')
					|| (i == 0 && value[i] == '-')))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	if (data.is_stack == 1)
		add_node_to_top(stack, atoi(value));
	else
		add_node_to_end(stack, atoi(value));
}
/**
 * pall - prints the elements of the stack
 * @stack: stack
 * @line_number: nuber of the line
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}
