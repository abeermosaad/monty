#include "monty.h"

int is_opcode(char *line, instruction_t opcode[])
{
	int i;
	for (i = 0; i < 1; i++)
	{
		if(strcmp(line, opcode[i].opcode) == 0)
			return (i);
	}
	return (-1);
}
