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
 *
 * Return: void
 */

instruction_t vinstruction[] = {
	{"push", &push},
	{"pall", &pall},
	{"pop", &pop},
	{"add", &add},
	{"pint", &pint},
	{"swap", &swap},
	{"nop", &nop},
	{"sub", &sub},
	{"div", &division},
	{"mul", &mul},
	{"mod", &mod},
};
void pinst(const char* instruction, int line_number, stack_t **stack)
{
	int num_instructions = sizeof(vinstruction) / sizeof(vinstruction[0]);
	int i;

	for (i = 0; i < num_instructions; i++)
	{
		if (strcmp(instruction, vinstruction[i].opcode) == 0)
		{
			vinstruction[i].f(stack, line_number);
			return;
		}
	}

	printf("L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
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

