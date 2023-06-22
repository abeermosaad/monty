#include "monty.h"
/**
 * pstr - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void)line_number;

	if (!(*stack))
	{
		free_list(stack);
	}
	while (curr && ((curr)->n > 0 && (curr)->n < 127))
	{
		fprintf(stdout, "%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
/**
 * rotl - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *new_node;
	stack_t *current = *stack;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		return;
	}
	num = (*stack)->n;
	pop(stack, line_number);
	while (current->next)
		current = current->next;
	new_node->n = num;
	current->next = new_node;
	new_node->prev = current->next;
	new_node->next = NULL;
}


