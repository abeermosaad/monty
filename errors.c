#include "monty.h"
/**
 * 
 * 
*/
void error_argc()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * 
 * 
*/
void error_file(const char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}
/**
 * 
 * 
*/
void error_instruction(int count, char *line_copy, char *line)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", count, line_copy);
	free(line);
	exit(EXIT_FAILURE);
}
