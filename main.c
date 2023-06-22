#define _POSIX_C_SOURCE 200809L
#include "monty.h"
char *value;

/**
 * main - Function that run our interpreter
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: .
*/
int main(int argc, char const *argv[])
{
	char *line = NULL, *line_copy, *instruction;
	size_t len = 0;
	ssize_t read;
	FILE *file;
	unsigned int count = 0;
	int idx;
	instruction_t opcode[] = {{"push", push}, {"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"pchar", pchar}};
	stack_t *stack = NULL;

	if (argc != 2)
		error_argc();
	file = fopen(argv[1], "r");
	if (file == NULL)
		error_file(argv[1]);
	while (1)
	{
		count++;
		read = getline(&line, &len, file);
		if (read == -1)
			break;
		line_copy = handle_new_line(line);
		if (strcmp(line_copy, "\n") == 0)
			continue;
		instruction = strtok(line_copy, TOK_DELIM);
		value = strtok(NULL, TOK_DELIM);
		idx = is_opcode(instruction, opcode);
		if (idx >= 0)
			opcode[idx].f(&stack, count);
		else
		{
			free_list(&stack);
			error_instruction(count, line_copy, line);
		}
	}
	free(line);
	free_list(&stack);
	fclose(file);
	return (0);
}
