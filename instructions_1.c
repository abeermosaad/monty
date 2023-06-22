#include "monty.h"
/**
 * pchar - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!((*stack)->n > 0 && (*stack)->n < 127))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
/**
 * mul - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = (*stack)->n;
	(*stack)->next->n *= num;
	(*stack)->next->prev = NULL;
	free(temp);
	*stack = (*stack)->next;
}
/**
 * mod - .
 * @stack: .
 * @line_number: .
 * Return: .
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		free_list(stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	num = (*stack)->n;
	(*stack)->next->n %= num;
	(*stack)->next->prev = NULL;
	free(temp);
	*stack = (*stack)->next;
}
