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
	instruction_t opcode[] = {{"push", push}, {"pall", pall}};
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL || access(argv[1], X_OK))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
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
			fprintf(stderr, "L%d: unknown instruction %s\n", count, line_copy);
			exit(EXIT_FAILURE);
		}
	}
	free_list(&stack);
	free(line);
	fclose(file);
	return (0);
}
