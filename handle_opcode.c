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
 * is_int - .
 * @value: .
 * Return: .
*/

int is_int(char *value)
{
	char *ptr = value;

	if (value == NULL)
		return (0);
	while (*ptr != '\0')
	{
		if (*ptr >= '0' && *ptr <= '9')
			ptr++;
		else
			return (0);
	}

	return (1);
}
