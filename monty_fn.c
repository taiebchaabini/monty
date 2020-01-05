#include "monty.h"
int argn;
/**
* checkInt - Checks if each value of given string is an int and transform it values to integers
* @arg - String to transform to int
* @linen - Current <instruction> line number
* Return: given string to integer.
**/
int checkInt(char *arg, unsigned int linen)
{
	int i = 0, val = 0;

	while (arg[i] != '\0')
	{
		if (arg[i] >= 48 && arg[i] <= 57)
			i++;
		else
		{
			printf("L%d: usage: push integer\n", linen);
			exit(EXIT_FAILURE);
		}
	}
	val = atoi(arg);
	return (val);
}

/**
* _push - pushes an element to the stack.
* Usage: push <int>
**/
void _push(stack_t **stack, unsigned int line_number)
{
	printf("L%d:PUSH EXECUTED and value is %d\n", line_number, argn);
}
void _pall(stack_t **stack, unsigned int line_number)
{
	printf("L%d:PALL EXECUTED\n", line_number);
}
/**
* getOpcodeFn - checks if opcode exist and return it function.
**/
void (*getOpcode(char *opcode, char *arg, unsigned int line_number))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			if (strcmp(opcode, "push") == 0)
				argn = checkInt(arg, line_number);
			return opcodes[i].f;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
*
**/
void instruction(char *opcode, char *arg, unsigned int line_number)
{
	stack_t **stack;
	getOpcode(opcode, arg, line_number)(stack, line_number);
}
/**
 * interpreter - runs the bytecodes line by line and stop if :
 * - it executed properly every line of the file
 * - it finds an error in the file
 * - an error occured
 * @data: bytecodes data
 **/
void interpreter(char *filename)
{
	FILE *fp;
	size_t len = 1;
	ssize_t read;
	char *data = NULL, *opcode = NULL, *arg = NULL;
	int linen = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&data, &len, fp)) != -1)
	{
		opcode = strtok(data, " \n");
		arg = strtok(NULL, " \n");
		/** MY INSTRUCTIOn COMES HERE **/
		instruction(opcode, arg, linen);
		/** COUNT LINES **/
		linen++;
	}
	free(data);
	fclose(fp);
	exit(0);
}
