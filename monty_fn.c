#include "monty.h"
int argn;
/**
* checkInt - Checks if each value of given string is an int and transform it
* values to integers
* @arg: String to transform to int
* @linen: Current <instruction> line number
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
* @stack: stack_t pointer to pointer
* @line_number: current <instruction> line_number
**/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *head = NULL, *new = NULL;

	add_dnodeint(stack, argn);
}
/**
* _pall - prints all the values on the stack, starting from
* the top of the stack.
* @stack: stack_t pointer to pointer
* @line_number: current <instruction> line_number
**/
void _pall(stack_t **stack, unsigned int line_number)
{
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
/**
* instruction - checks if opcode exist and execute it function.
* @opcode: opcode of function to execute
* @arg: argument to pass to this function
* @linen: line number of instruction
* Return: pointer to function
**/
void (*instruction(char *opcode, char *arg, unsigned int linen))
(stack_t **stack, unsigned int line_number)
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
				argn = checkInt(arg, linen);
			return (opcodes[i].f);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", linen, opcode);
	exit(EXIT_FAILURE);
}
/**
 * interpreter - runs the bytecodes line by line and stop if :
 * - it executed properly every line of the file
 * - it finds an error in the file
 * - an error occured
 * @filename: file to read
 **/
void interpreter(char *filename)
{
	FILE *fp;
	size_t len = 1;
	ssize_t read;
	char *data = NULL, *opcode = NULL, *arg = NULL;
	int linen = 1;
	stack_t *stack = NULL;

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
		(*instruction(opcode, arg, linen))(&stack, linen);
		/** COUNT LINES **/
		linen++;
	}
	free(data);
	free_stack_t(stack);
	fclose(fp);
	exit(0);
}
