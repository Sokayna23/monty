#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: stack
 * @line_number: number of lines
 * Return: nothing
 */
void push(stack_t **stack, char *argument, unsigned int line_number)
{
	if (!is_digit(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	add_node_to_top(stack, line_number);
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
