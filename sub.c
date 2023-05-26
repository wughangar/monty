#include "monty.h"

/**
 * sub - function that subtracts top element from second
 * @stack: pointer to top element
 * @line_number: line number
 *
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
