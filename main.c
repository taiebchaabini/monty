#include "monty.h"
int main(int ac, char **av)
{
	char *data;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	data = getData(av[1]);
	interpreter(data);
	return (0);
}
