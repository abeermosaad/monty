#include "monty.h"
/**
 * error_argc - .
 * Return: .
*/
void error_argc(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * error_file - .
 * @file: .
 * Return: .
*/
void error_file(const char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * error_instruction - .
 * @line: .
 * @line_copy: .
 * @count: .
 * Return: .
*/
void error_instruction(int count, char *line_copy, char *line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", count, line_copy);
	free(line);
	exit(EXIT_FAILURE);
}
