#include "monty.h"

#define STACK_SIZE 1024

/**
 * push - function for push
 * @stack: stack
 * @value: int
 *
 * Return: void
 */
void push(Stack *stack, int value)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "Error: Satck overflow\n");
		exit(EXIT_FAILURE);
	}
	stack->data[++stack->top] = value;
}

/**
 * pall - function for pall
 * @stack: stack
 *
 * Return: void
 */

void pall(Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
	{
		pintf("%d\n", stack->data[i]);
	}
}
