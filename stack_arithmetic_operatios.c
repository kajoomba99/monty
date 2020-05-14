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
/**
 * sub - The opcode sub subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void sub(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	sub = tmp->n - tmp->prev->n;
	tmp->n = sub;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}
/**
 * _div - The opcode div divides the second top element of the
 * stack by the top element of the stack.
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void _div(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}

	div = tmp->n / tmp->prev->n;
	tmp->n = div;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}
/**
 * _mul - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void _mul(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	mul = tmp->n * tmp->prev->n;
	tmp->n = mul;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}
/**
 * _mod - The opcode mul multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: This is the head of the parameters
 * @ln: is a number of the line when there is a wrong.
 */
void _mod(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = NULL;
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if ((*stack)->n == 0){
		fprintf(stderr, "L%d: division by zero\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}
	mod = tmp->n % tmp->prev->n;
	tmp->n = mod;
	free(tmp->prev);
	*stack = tmp;
	tmp->prev = NULL;
}
