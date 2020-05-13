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
	stack = NULL;
	fp = NULL;
	line = NULL;
}
/**
 * free_prog - free_prog
 */
void free_prog(void)
{
	if (fp  != NULL)
		fclose(fp);
	if (line  != NULL)
		free(line);
	if (stack != NULL)
		free_list(stack);
}
