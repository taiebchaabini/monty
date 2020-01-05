OBJS = *.c
OBJ_NAME = monty
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic
#COMPILER_FLAG = 
CC = gcc
all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
