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
		exit(EXIT_FAILURE);
	}
}
/**
 * *open_monty_script - a function that open the monty script.
 * @filename: name of the file for open with monty
 * Return: a pointer
 */
FILE *open_monty_script(char *filename)
{

	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (fp);
}
/**
 * read_monty_script - a function that read the monty script.
 * @fp: is a pointer
 */
void read_monty_script(FILE *fp)
{
	int f_line = 0;
	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, fp) != -1)
	{
		choose_instruction(line, f_line);
		f_line++;
	}
}
/**
 * choose_instruction - a function that choose any instruction.
 * @line: is a line give it for the token
 * @ln: is a unsigned integer fo count
 */
void choose_instruction(char *line, unsigned int ln)
{
	char *token = NULL;
	char *data = NULL;
	int i_data = 0, i = 0;

	instruction_t options[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};

	token = strtok(line, " \n");
	data = strtok(NULL, " \n");
	if (data != NULL && token != NULL)
	{
		if (_isdigit(data) && strcmp(token, "push") == 0)
		{
			i_data = atoi(data);
			push(&stack, i_data);
			return;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
	for (i = 0; options[i].opcode; i++)
	{
		if (strcmp(token, options[i].opcode) == 0)
		{
			options[i].f(&stack, ln);
			break;
		}
	}
	if (options[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, token);
		exit(EXIT_FAILURE);
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