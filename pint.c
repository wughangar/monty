#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint - function for pint
 * @stack: double pointer for stack
 * @line_number: unsigned int
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
