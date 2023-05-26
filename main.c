#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * main - monty code interpretor
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: int
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	char *opcode;
	int value;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || strcmp(opcode, "") == 0)
		{
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			if (value == 0 && strcmp(arg, "0") != 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(instruction, "pint") == 0)
		{
			pint(stack, line_number);
		}
		else if (strcmp(instruction, "swap") == 0)
		{
			swap(stack, line_number);
		}
		else if (strcmp(instruction, "nop") == 0)
		{
			nop(stack, line_number);
		}
		else if (strcmp(instruction, "sub") == 0)
		{
			sub(stack, line_number);
		}
		else if (strcmp(instruction, "div") == 0)
		{
			division(stack, line_number);
		}
		else if (strcmp(instruction, "mul") == 0)
		{
			mul(stack, line_number);
		}
		else if (strcmp(instruction, "mod") == 0)
		{
			mod(stack, line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, instruction);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free(line);
	free_stack(stack);

	return (0);
}

