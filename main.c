#include "monty.h"
/**
* main - The monty program interpreter for monty byte code files
* @ac: number of arguments
* @av: arguments passed to the program
* Return: 0 otherwise EXIT_FAILURE
**/
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	interpreter(av[1]);
	return (0);
}
