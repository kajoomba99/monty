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
	(void) line_number;
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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
