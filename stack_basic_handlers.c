#include "monty.h"

/**
 * push - The opcode push pushes an element to the stack.
 * @stack: This is the head of the parameters
 * @data: unity of information of the imput parameters.
 * @ln: ln
 * Return: the new node
 */
stack_t *push(stack_t **stack, char *data, unsigned int ln)
{
	int i_data = 0;
	stack_t *new_node = NULL;

	if (data != NULL && _isdigit(data))
		i_data = atoi(data);

	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_prog();
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_prog();
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = i_data;
	if (*stack == NULL)
	{
		*stack = new_node;
		return (new_node);
	}

	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
	return (new_node);
}

/**
 * pop - The opcode pop removes the top element of the stack.
 * @stack: This is the head of the parameters
 * @line_number: is a number of the line when there is a wrong.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_prog();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	*stack = (*stack)->next;
	free(temp);
}
