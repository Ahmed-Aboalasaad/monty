#include "monty.h"

/**
 * freeStack - frees a dlistint_t list
 *
 * @head: the list head
 * Return: nothing
*/
void freeStack(stack_t *head)
{
	stack_t *tmp;

	if (!head)
		return;
	for (tmp = head; head->next; head = tmp)
	{
		tmp = head->next;
		free(head);
	}
	free(head);
}

/**
 * getOperation - gets a function pointer to the operation related
 * to the given opcode
 *
 * @instruction: pointer to the first element of the instructions array in main
 * @opcode: a string haveing the opcde to search for it (ex: push)
 * Return: the corresponding function pointer,
 * or NULL if it fails (no such operation exists)
*/
void (*getOperation(instruction_t *instructions, Command *command))
	 (stack_t **stack, unsigned int line_number)
{
	int i;

	if (instructions[0].opcode)
		printf("existent\n");
	else
		printf("Nope\n");

	printf("getOperation() before for loop\n");
	for (i = 0; instructions[i].opcode; i++)
	{
		printf("iteration #%d ", i + 1);
		if (isEqual(instructions[i].opcode, command->word))
			return (instructions[i].f);
	}
	printf("L<line_number>: unknown instruction %s\n", command->word);
	exit(EXIT_FAILURE); // potential memory leak: exit safely
}

/**
 * getInstructions - makes an array of instructions
 *
 * Return: pointer to the first element of this array
*/
instruction_t *getInstructions()
{
	int instructionsNum = 2;
	instruction_t *i;

	i = malloc(sizeof(*i) * (instructionsNum + 1));

	i[0].opcode = "push";
	i[0].f = push;
	i[1].opcode = "pall";
	i[1].f = pall;
	i[2].opcode = NULL;
	i[2].f = NULL;

	return (i);
}

int main(int argc, char** argv)
{
	char *buffer;
	int lineNumber = 345;
	unsigned long bufferSize, lineCount;
	FILE *file;
	void (*operation)(stack_t **stack, unsigned int line_number);
	Command *command;
	stack_t *head = NULL;
	instruction_t *instructions;

	/* Usage Assertion */
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open the file */
	file = fopen(argv[1], "r");
	if (!file)
	{
		// todo: only the file name not the full path
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* prepare the buffer */
	bufferSize = 100;
	buffer = malloc(sizeof(char) * (bufferSize));
	if (!buffer)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	buffer[bufferSize - 1] = '\0';

	/* Implement the instructions */
	instructions = getInstructions();
	// todo: make the lineCount a global variable
	for (lineCount = 0; getline(&buffer, &bufferSize, file) != -1; lineCount++)
	{
		command = buildCommand(buffer);
		operation = getOperation(instructions, command);
		printf("operation returned\n");
		operation(&head, command->n);
	}
	free(buffer); // potential memory leak
	freeStack(head);
	fclose(file);

	return (0);
}
