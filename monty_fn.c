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
* tokenLength - count the numbers of char in a token using \n and " " delimiters
* @token: data to count
* Return: Numbers of char in a subtoken after delim.
**/
int tokenLength(char *token)
{
	char *subtoken = NULL, *saveptr = NULL, *tmp = NULL, *str = NULL;
	int i = 0;

	tmp = malloc(sizeof(char) * strlen(token));
	tmp = strdup(tmp); 
	str = strtok(tmp, "\n");
	while (str != NULL)
	{
		subtoken = strtok_r(str, " ", &saveptr);
		while (subtoken != NULL)
		{
			i += strlen(subtoken);
			subtoken = strtok_r(NULL, " ", &saveptr);
		}
		str = strtok(NULL, "\n");
	}
	return (i);
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
	char *token = NULL, *subtoken = NULL, *saveptr = NULL;
	int tokenLen = 0, i = 0;

	token = strtok(data, "\n");
	while (token != NULL)
	{
		i = 0;
		tokenLen = tokenLength(token);
		printf("Token SIZE IS %d\n", tokenLen);
		subtoken = strtok_r(token, " ", &saveptr);
		while (subtoken != NULL)
		{
			printf("Subtoken is %s\n", subtoken);
			i++;
			subtoken = strtok_r(NULL, " ", &saveptr);
		}
		token = strtok(NULL, "\n");
	}
}
