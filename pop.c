#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - function for pop
 * @stack: double pointer for stack
 * @num: unsigned int
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int num)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
