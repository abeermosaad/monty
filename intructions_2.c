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
	while (curr && (curr->n != 0) && ((*stack)->n > 0 && (*stack)->n < 127))
	{
		fprintf(stdout, "%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
