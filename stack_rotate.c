#include "monty.h"
/**
 * rotl - rotl
 * @stack: stack
 * @ln:ln
 */
void rotl(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack, *last = *stack;

	(void) ln;
	if (stack != NULL && *stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
	}
}
