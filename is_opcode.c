#include "monty.h"
/**
 * is_opcode - .
 * @line: .
 * @opcode: .
 * Return: .
*/
int is_opcode(char *line, instruction_t opcode[])
{
	int i;

	for (i = 0; i < 12; i++)
	{
		if (strcmp(line, opcode[i].opcode) == 0)
			return (i);
	}
	return (-1);
}
