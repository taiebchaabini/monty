#include "monty.h"
/**
* getData - Get data from the file
* @filename: input filename (argv[1])
* Return: data from the <file>
**/
char *getData(char *filename)
{
	int fd, i = 0;
	size_t buffer = 1;
	char buf[1024];
	char *data = buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((buffer = read(fd, data, 1024)) > 0)
		i += buffer + i;
	data[i] = '\0';
	close(fd);
	return (data);
}
/**
* interpreter - runs the bytecodes line by line and stop if :
* - it executed properly every line of the file
* - it finds an error in the file
* - an error occured
* @data: bytecodes data
**/
void interpreter(char *data)
{
	char *token = NULL;

	token = strtok(data, "\n");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "\n");
	}
}
