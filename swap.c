#include "monty.h"

/**
 * swap - function that swapstop two elements
 * @stack: pinter to stack
 * @line-number: int for line number
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int x;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}
