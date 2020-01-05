#include "monty.h"
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	interpreter(av[1]);
	return (0);
}
