#include "monty.h"
/**
 * push - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int is_num, number;

	is_num = is_int(value);
	if ((!is_num))
	{
		free_list(&new_node);
		free_list(stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	number = atoi(value);
	new_node->n = number;
	new_node->prev = NULL;
	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
/**
 * free_list - .
 * @stack: .
 * Return: .
*/
void free_list(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *free_me;

	while (curr != NULL)
	{
		free_me = curr;
		curr = curr->next;
		free(free_me);
	}
	*stack = NULL;
}
