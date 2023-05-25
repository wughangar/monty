#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: pointer to argument vector
 *
 * Return: int
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char line[100];
	unsigned int num  = 0;
	char *opcode;
	FILE *file;
	char *arg = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
		num++;
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
				fprintf(stderr, "L%u: usage: push integer\n", num);
				exit(EXIT_FAILURE);
			}
			push(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, num);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, num);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, num);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "push") == 0)
		{
			push(&stack);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", num, opcode);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
