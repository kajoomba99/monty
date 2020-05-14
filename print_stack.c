#include "monty.h"

/**
 * pall - The opcode pall prints all the values on the stack, starting
 * from the top of the stack
 * @stack: This is the head of the parameters
 * @line_number: is a number of the line when there is a wrong.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *box;
	(void)line_number;
	if (*stack == NULL)
		return;
	box = *stack;
	while (box != NULL)
	{
		printf("%d\n", box->n);
		box = box->next;
	}
}

/**
 * pint - The opcode pint prints the value at the top of the stack,
 * followed by a new line..
 * @stack: This is the head of the parameters
 * @line_number: is a number of the line when there is a wrong.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_prog();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the top of the stack
 * @ln: line number of the current executing script
 */
void pchar(stack_t **stack, unsigned int ln)
{
	int ch = 0;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (ch < 0 || ch > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	putchar(ch);
	putchar(10);
}
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the top of the stack
 * @ln: line number of the current executing script
 */
void pstr(stack_t **stack, unsigned int ln)
{
	int ch = 0;
	stack_t *temp = *stack;
	(void) ln;

	if (*stack == NULL)
	{
		putchar(10);
		return;
	}
	while (temp != NULL)
	{
		ch = temp->n;
		if (ch < 1 || ch > 127)
		{
			putchar(10);
			return;
		}
		putchar(ch);
		temp = temp->next;
	}
	putchar(10);
}
