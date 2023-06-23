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
	stack_t *current = *stack;
	(void)line_number;

	if ((*stack) && ((*stack)->next))
	{
		num = (*stack)->n;
		while (current->next != NULL)
		{
			current->n = current->next->n;
			current = current->next;
		}
		current->n = num;
	}
}

/**
 * rotr - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *current = *stack;
	(void)line_number;

	if ((*stack) && ((*stack)->next))
	{		
		while (current->next != NULL)
		{
			current = current->next;
		}
		num = current->n;
		while (current != (*stack))
		{
			current->n = current->prev->n;
			current = current->prev;
		}
		(*stack)->n = num;
	}
}
