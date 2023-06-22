#include "monty.h"
/**
 * handle_new_line - Function handles the line that user enters
 * @line: Take the line from getline function
 * Return: The handled string without new line(\n)
*/
char *handle_new_line(char *line)
{
	int len, i = 0;

	while (line[i])
	{
		if (line[i] != ' ')
		{
			line += i;
			break;
		}
		i++;
	}
	len = (int)strlen(line);
	if (len == 1 && line[0] == '\n')
		return (line);

	len = (int)strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}
/**
 * generate_argv - Function That generate all the arguments
 * @line: take the line from getline function
 * Return: array of strings (Vector)
*/
char **generate_argv(char *line)
{
	char **argv, *argv_idx;
	int i = 0;

	argv = malloc(sizeof(char *) * (strlen(line) + 1));

	if (!argv)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	argv_idx = strtok(line, TOK_DELIM);
	while (argv_idx)
	{
		if (argv_idx[0] == '#')
			break;
		argv[i] = argv_idx;
		argv_idx = strtok(NULL, TOK_DELIM);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

int is_int(char *value)
{
	char *ptr = value;

	while (*ptr != '\0')
	{
		if (*ptr >= '0' && *ptr <= '9')
			ptr++;
		else
			return (0);
	}

	return (1);
}
