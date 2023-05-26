#include "monty.h"

/**
 * add - functions that adds top two elements
 * @stack: pointer to top element of the stack
 * @line_number: int for line number
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	total = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = total;
}
