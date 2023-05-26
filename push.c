#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_numeric - function that checks if its numeric
 * @str: string tobe checked
 *
 * Return: int
 */

int is_numeric(const char* str)
{
	size_t i;

       	if (str == NULL || *str == '\0')
	{
		return 0;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
	}

	return (1);
}

/**
 * push - function for push 
 * @stack: double pointer  to stack
 * @line_number: int for line mumber 
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, "\t\n");
	int value;
	stack_t *new_node;

	if (arg == NULL || !is_numeric(arg))
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
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



