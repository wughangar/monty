#include "monty.h"

/**
 * mul - function thats multiplies top elemnts
 * @stack: pointer to top elemenst of the stack
 * @line_number: line number
 *
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
