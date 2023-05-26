#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * pinst - fuction to process instructions
 * @instruction: instruction to be processed
 * @line_number: line number
 * @stack: pinter for stack
 *
 * Return: void
 */

void pinst(const char* instruction, int line_number, stack_t **stack)
{
	if (strcmp(instruction, "push") == 0)
	{
		push(&stack);
	}
	else if (strcmp(instruction, "pall") == 0)
	{
		pall(&stack);
	}
	else if (strcmp(instruction, "pop") == 0)
	{
		pop(&stack);
	}
	else if (strcmp(instruction, "add") == 0)
	{
		add(&stack);
	}
	else if (strcmp(instruction, "pint") == 0)
	{
		pint(&stack);
	}
	else if (strcmp(instruction, "swap") == 0)
	{
		swap(&stack);
	}
	else if (strcmp(instruction, "nop") == 0)
	{
		nop(&stack);
	}
	else if (strcmp(instruction, "sub") == 0)
	{
		sub(&stack);
	}
	else if (strcmp(instruction, "div") == 0)
	{
		division(&stack);
	}
	else if (strcmp(instruction, "mul") == 0)
	{
		mul(&stack);
	}
	else if (strcmp(instruction, "mod") == 0)
	{
		mod(&stack);
	}

	else
	{
		printf("L%d: unknown instruction %s\n", line_number, instruction);
		exit(EXIT_FAILURE);
	}
}
			

/**
 * main - monty code interpretor
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: int
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	FILE *file;
	char *line;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		char *instruction = strtok(line, "\t\n");

		if (instruction != NULL)
		{
			pinst(instruction, line_number, &stack);
		}
		line_number++;
	}
	fclose(file);
	free(line);
	free_stack(stack);

	return (0);
}

