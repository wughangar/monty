#include <stdio.h>
#include "monty.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - function for push
 * @stack: double pointer  to stack
 * @line_number: int for line mumber
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char line_str[20];

	sprintf(line_str, "%u", line_number);

	if (!is_numeric(line_str))
	{
		fprintf("Error: L%u: ussage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf("Errror: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

#include "monty.h"

/**
 * pall - function that prints all the  values on the stack
 * @stack: pointer to stack
 * @line_number: int for line number
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * free_stack - function that frees the stack
 * @stack: pointer to stack
 *
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
