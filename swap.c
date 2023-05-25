#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - function for swap
 * @stack: double pointer for stack
 * @line_number: unsigned int
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;

	second->prev = NULL;
	second->next = top;
	top->next = second;

	*stack = second;
}
