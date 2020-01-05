#include "monty.h"
/**
* main - The monty program interpreter for monty byte code files 
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
