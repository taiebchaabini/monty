OBJS = *.c
OBJ_NAME = monty
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic
CC = gcc
all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
