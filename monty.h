#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct monty_data
{	char * input_value;
	int is_stack;
	int status;
} monty_data_t;
extern monty_data_t data;

/*opcode functions*/
void push(stack_t **stack, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* linked list functions*/
size_t print_stack(const stack_t *stack);
stack_t *add_node_to_end(stack_t **stack, const int n);
stack_t *add_node_to_top(stack_t **stack, const int n);
void free_stack(stack_t **stack);

/* opcode function selecter*/
void (*get_opcode_func(char *instruction))(stack_t **, unsigned int);
#endif
