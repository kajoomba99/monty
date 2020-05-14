#include "monty.h"
/**
 * verify_args - a function that verify the arguments.
 * @c: parameter integer
 */
void verify_args(int c)
{
	if (c != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_prog();
	}
}
/**
 * *open_monty_script - a function that open the monty script.
 * @filename: name of the file for open with monty
 * Return: a pointer
 */
void open_monty_script(char *filename)
{
	variables.fp = fopen(filename, "r");

	if (variables.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free_prog();
	}
}
/**
 * read_monty_script - a function that read the monty script.
 */
void read_monty_script(void)
{
	int f_line = 1;
	size_t len = 0;

	while (getline(&variables.line, &len, variables.fp) != -1)
	{
		choose_instruction(f_line);
		f_line++;
	}
}
/**
 * choose_instruction - a function that choose any instruction.
 * @ln: is a unsigned integer fo count
 */
void choose_instruction(unsigned int ln)
{
	char *token = NULL;
	char *data = NULL;
	int i_data = 0, i = 0;

	instruction_t options[] = {{"pall", pall}, {"pint", pint}, {"pop", pop},
	{"swap", swap}, {"add", add}, {"sub", sub}, {"div", _div}, {"mul", _mul},
	{"mod", _mod},
	{"nop", nop}, {"pchar", pchar}, {"pstr", pstr}, {NULL, NULL}};
	token = strtok(variables.line, " \n");
	if (token == NULL || token[0] == '#')
		return;
	data = strtok(NULL, " \n");
	if (strcmp(token, "push") == 0)
	{
		if (data != NULL && _isdigit(data))
		{
			i_data = atoi(data);
			push(&variables.stack, i_data);
			return;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_prog();
		}
	}

	for (i = 0; options[i].opcode; i++)
	{
		if (strcmp(token, options[i].opcode) == 0)
		{
			options[i].f(&variables.stack, ln);
			break;
		}
	}
	if (options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, token);
		free_prog();
	}
}
/**
 * _isdigit -_isdigit
 * @number: number
 * Return: 1 if @number is a numbe, 0 if it's not
 */
int _isdigit(char *number)
{
	int i = 0;

	if (number == NULL)
		return (0);
	if (number[0] == '-')
		i++;
	for (; number[i] != '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
	}
	return (1);
}
