#include "monty.h"
/**
* _strcpy - function that copies the string pointed to by src
* , including the terminating null byte (\0), to the buffer pointed to by dest.
* of an array of integers, followed by a new line.
* @dest: pointer to char
* @src: pointer to char
* Return: Value returned to pointer @dest
**/

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int n = 0;

	while (src[n] != '\0')
		n++;
	for (i = 0; i < n; i++)
		dest[i] = src[i];
	for (i = i; i <= n; i++)
		dest[i] = '\0';
	return (dest);
}
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
	char *saveptr = NULL; char *tmp = NULL;
	int i = 0;

	token = strtok_r(token, " ", &saveptr);
	while (token != NULL)
	{
		i += strlen(token);
		token = strtok_r(NULL, " ", &saveptr);
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
	char *token = NULL, *subtoken = NULL, *saveptr = NULL, *tmp = NULL;
	int tokenLen = 0, i = 0;

	token = strtok(data, "\n");
	while (token != NULL)
	{
		i = 0;
		tmp = malloc(sizeof(char) * strlen(token));
		tmp = strcpy(tmp, token);
		tokenLen = tokenLength(tmp);
		printf("[TOKEN][%d] IS %s\n", tokenLen, token);
	/*	subtoken = strtok_r(token, " \n", &saveptr);
		while (subtoken != NULL)
		{
			printf("--------> SUB TOKEN IS : %s\n", subtoken);
			i++;
			subtoken = strtok_r(NULL, " \n", &saveptr);
		}
	*/	token = strtok(NULL, "\n");
	}
}
