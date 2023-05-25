#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - function for add 
 * @stack: double pointer for the stack
 * @line_number: unsigned int
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
