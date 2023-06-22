#include "monty.h"
/**
 * swap - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int num;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

/**
 * add - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void add(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = (*stack)->n;
	(*stack)->next->n += num;
	(*stack)->next->prev = NULL;
	free(temp);
	*stack = (*stack)->next;
}
