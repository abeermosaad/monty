#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int is_num, number;


	is_num = is_int(value);
	if(!is_num)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	number = atoi(value);
	new_node->n = number;
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}

	new_node->prev = NULL;
	new_node->next = *stack;

	(*stack)->prev = new_node;
}

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	temp = *stack;
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
