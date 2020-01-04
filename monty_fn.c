#include "monty.h"
void _push(void)
{
	printf("PUSH EXECUTED\n");
}
void _pull(void)
{
	printf("PULL EXECUTED\n");
}
/**
*
**/
void instruction(char *opcode, char *arg, unsigned int line_number)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"push", _push},
		{"pull", _pull},
		{NULL, NULL}
	};
	while (opcodes[i].opcode)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			printf("OPCODE found");
			break;
		}
	}
	printf("L%d:OPCODE IS %s, value %s\n", line_number, opcode, arg);

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
	int linen = 1, i = 0;
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
		instruction(args[0], args[1], linen);
		linen++;
		token = strtok(NULL, "\n");
	}
}
