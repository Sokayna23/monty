#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number (to print in the error message)
 * Return: Nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1 = NULL;
	int top2 = 0;

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	top1 = *stack;
	top2 = top1->n;
	top1->n = top1->next->n;
	top1->next->n = top2;
}
