#include "monty.h"

/**
 * pall - function that prints all the  values on the stack
 * @stack: pointer to stack
 * @line_number: int for line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
