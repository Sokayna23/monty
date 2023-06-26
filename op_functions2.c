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

	if (*stack == NULL || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	top1 = (*stack)->n;
	top2 = (*stack)->next->n;
	(*stack)->n = top2;
	(*stack)->next->n = top1;
}
/**
 * add - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line number(for printing error message)
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result, top1, top2;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	top1 = (*stack)->n;
	top2 = (*stack)->next->n;
	result = top1 + top2;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * sub - substracts the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int result, top1, top2;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	top1 = (*stack)->n;
	top2 = (*stack)->next->n;
	result = top2 - top1;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * _div - divides the second top element
 * of the stack by the top element
 * @stack: stack
 * @line_number: line number
 * Return: nothing.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		data.status = EXIT_FAILURE;
		return;
	}
	result = ((*stack)->next->n) / ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = result;
}
