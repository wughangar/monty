#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * is_numeric - function that checks for an in
 * @str: string to be checked
 *
 * Return: int
 */

int is_numeric(const char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}

	if (*str == '\0')
	{
		return (0);
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{

			return (0);
		}
	str++;
	}
	return (1);
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
	unsigned int line_number = 0;
	FILE *file;
	char *line = NULL;
	stack_t *stack = NULL;
	char *opcode;
	int value;
	size_t len = 0;

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

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || strcmp(opcode, "") == 0)
		{
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \t\n");

			if (arg == NULL || is_numeric(arg) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
			continue;
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
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else if (strcmp(opcode, "sub") == 0)
		{
			sub(&stack, line_number);
		}
		else if (strcmp(opcode, "div") == 0)
		{
			division(&stack, line_number);
		}
		else if (strcmp(opcode, "mul") == 0)
		{
			mul(&stack, line_number);
		}
		else if (strcmp(opcode, "mod") == 0)
		{
			mod(&stack, line_number);
		}
		else
		{
			printf("L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	free(line);
	free_stack(stack);

	return (0);
}

