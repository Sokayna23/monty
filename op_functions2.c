#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number (to print in the error message)
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top1, top2;

	data.line_number = line_number;
	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", data.line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	top1 = (*stack)->n;
	top2 = (*stack)->next->n;
	(*stack)->n = top2;
	(*stack)->next->n = top1;
}
