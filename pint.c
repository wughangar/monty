#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint - function for pint
 * @stack: double pointer for stack
 * @num: unsigned int
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
