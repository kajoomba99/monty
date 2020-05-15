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
	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
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

/**
 * rotr - rotr
 * @stack: stack
 * @ln:ln
 */
void rotr(stack_t **stack, unsigned int ln)
{
	stack_t *last = *stack;
	(void) ln;

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = (*stack);
		(*stack)->prev = last;
		*stack = (*stack)->prev;
	}
}
