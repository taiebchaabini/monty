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
 * interpreter - runs the bytecodes line by line and stop if :
 * - it executed properly every line of the file
 * - it finds an error in the file
 * - an error occured
 * @data: bytecodes data
 **/
void interpreter(char *data)
{
	char *token = NULL, *subtoken = NULL, *saveptr = NULL, *tmp = NULL;
	int line = 1, i = 0;
	char *args[2];

	token = strtok(data, "\n");
	while (token != NULL)
	{
		i = 0;
		subtoken = strtok_r(token, " \n", &saveptr);
		while (subtoken != NULL)
		{
			args[i] = subtoken; 
			i++;
			if (strcmp(args[0], "push") == 0)
			;
			else
			{
				args[1] = NULL;
				break;
			}
			subtoken = strtok_r(NULL, " \n", &saveptr);
		}
		/** MY EXECUTION COMES HERE **/

		line++;
		token = strtok(NULL, "\n");
	}
	printf("Lines %d\n", line -1);
}
