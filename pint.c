#include "monty.h"

/**
 * pint - function that prints the value of the top stack
 * @stack: pointer for the stack
 * @line_number: int for line number
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: cant't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
