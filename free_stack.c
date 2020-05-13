#include "monty.h"
/**
 * free_list - free_list
 * @stack: stack
 */
void free_list(stack_t *stack)
{
	stack_t *p, *store;

	p = stack;

	while (p != NULL)
	{
		store = p->next;
		free(p);
		p = store;
	}
}
/**
 * init_vars - init_vars
 */
void init_vars(void)
{
	variables.stack = NULL;
	variables.fp = NULL;
	variables.line = NULL;
}
/**
 * free_prog - free_prog
 */
void free_prog(void)
{
	if (variables.fp  != NULL)
		fclose(variables.fp);
	if (variables.line  != NULL)
		free(variables.line);
	if (variables.stack != NULL)
		free_list(variables.stack);
}
