#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command - a cleaned opcode
 *
 * @word: the opcode itself (word)
 * @strArg: a string having the integer argument of this command (if any)
 * @n: the same argument but integer
 *
 * Description: the word & number that of a line in a monty bytecode file
*/
typedef struct command
{
	char *word;
	char *strArg;
	unsigned int n;
} Command;

/* Opcodes */
Command *buildCommand(char *line);
void push(stack_t **head, unsigned int n);
void pall(stack_t **head, unsigned int n);

/* String Manipulators */
char isEqual(char *s1, char *s2);
char *strSlice(char *s, unsigned int start, unsigned int end);
int strLen(char *s);
unsigned int strToInt(char *s);

char *getWord(char *line);

#endif
