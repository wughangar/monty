#include "monty.h"

/**
 * pop - function that removes the top element of the stack
 * @stack: pointer to top element of th stack
 * @line_number: int for line number
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		printf("L%d: cant't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
