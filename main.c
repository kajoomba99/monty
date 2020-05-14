#include "monty.h"
/**
 * main - this is the pricipal file where declarate the most or first
 * function for the correct funcionality of the program
 * @argc: is the command for recive all elements give it how no interactive
 * @argv: arguments recived for command line give it for keyboard.
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	init_vars();
	verify_args(argc);
	open_monty_script(argv[1]);
	read_monty_script();
	free_prog();
	return (0);
}

/**
 * swap- swap the first elemento for the second one element
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void swap(stack_t **stack, unsigned int ln)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * nop - The opcode nop doesn’t do anything..
 * @stack: This is the head of the parameters
 * @line_number: is a number of the line when there is a wrong.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
