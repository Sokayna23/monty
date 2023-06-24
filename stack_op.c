#include "monty.h"

/**
 * add_node_to_end - adds a node to the end of a stack_t stack
 * @stack: a pointer to a pointer to the first node
 * @n: the data to be added to the stack
 * Return: the address of the new node (Success), or
 * NULL if it failed
 */
stack_t *add_node_to_end(stack_t **stack, const int n)
{
	stack_t *node, *tmp = *stack;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->n = n;
	node->next = NULL;
	if (*stack == NULL)
	{
		node->prev = NULL;
		*stack = node;
		return (node);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	return (node);
}
/**
 * add_node_to_top - adds a node to tje top of a stack_t stack
 * @stack: a pointer to a pointer to the first element
 * @n: the data to be added to the stack
 * Return: the address of the new node (Success), or
 * NULL if it failed.
 */
stack_t *add_node_to_top(stack_t **stack, const int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
	return (node);
}
/**
 * print_stack - prints a stack_t stack
 * @stack: a pointer to the first elemnent in the stack
 * Return: the number of elements in the stack
 */
size_t print_stack(const stack_t *stack)
{
	size_t count_elmt = 0;

	if (stack == NULL)
		return (0);
	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		count_elmt++;
	}
	return (count_elmt);
}
/**
 * free_stack - frees a stack_t stack
 * @stack: the pointer poniting to the first element inthe stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
