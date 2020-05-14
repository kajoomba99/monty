#include "monty.h"

/**
 * add - a function that add the elements of the input parameters.
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void add(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	add = tmp->n + tmp->prev->n;
	tmp->n = add;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}
