#include "monty.h"

char *getWord(char *line);
char *getArg(char *line);

/**
 * buildCommand - parses a line of monty bytecode into a command structure
 * with the word representing the opcode and the integer argument in it
 *
 * @line: the line string
 * Return: pointer to the created structure, or NULL if it 
 * command->word string will be NULL if the line consists of only spaces
 * command->n string will be NULL if no argument was found & for syntax errors
*/
Command *buildCommand(char *line)
{
	Command *command;

	command = malloc(sizeof(*command));
	if (!command)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	command->word = getWord(line);
	if (!command->word)
	{
		free(command->word);
		free(command);
		return (NULL);
	}
	// printf("Building:\n");
	// printf("word= \"%s\"\n", command->word);

	line = strSlice(line, strLen(command->word), strLen(line) - 1);
	command->strArg = getArg(line);
	// printf("arg= \"%s\"\n", command->strArg);

	command->n = strToInt(command->strArg);
	// printf("integer arg = %d\n", command->n);

	// printf("\tLine address:  \t\t%p\n", line);
	// printf("\tcommand address: \t%p\n", (void *)command);
	// printf("\tcommand->word address: \t%p\n", command->word);
	// printf("\tcommand->strArg address: %p\n", command->strArg);

	return (command);
}

/**
 * getWord - gets the ward that the given line starts with
 * (optionally preceded with spaces)
 *
 * @line: the line to extract the word from
 * Return: the word if it was found, NULL otherwise
*/
char *getWord(char *line)
{
	int i, start, end; /* start & end indices of the word if any*/
	char isLetter, foundAWord, c;

	start = end = -1;
	for (i = foundAWord = 0; line[i]; i++)
	{
		c = line[i];
		isLetter = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');

		/* it it's the first space after the opcode */
		if (c == ' ' && foundAWord)
		{
			end = i - 1;
			return (strSlice(line, start, end));
		}

		/* if the line starts with characters other than letters & spaces */
		if (!isLetter && c != ' ')
			return (NULL);

		/* the word (opcode) started 
		(it's a letter and I didn't find one before) */
		if (isLetter && !foundAWord)
		{
			start = i;
			foundAWord = 1;
		}
	}
	/* a line of only spaces */
	return (0);
}

/**
 * getArg - gets the integer that the given line starts with
 * (optionally preceded with spaces)
 *
 * @line: the line to extract the integer from
 * Return: a string containing the integer if it was found, NULL otherwise
*/
char *getArg(char *line)
{
	int i, start; /* the start index of the number */
	char isNumber, foundANumber;

	for (i = foundANumber = 0, start = -1; line[i]; i++)
	{
		isNumber = line[i] >= '0' && line[i] <= '9';

		/* end of the number */
		if ((line[i] == ' ' || line[i] == '\n') && foundANumber)
			return (strSlice(line, start, i - 1));

		/* starts with a character other than the space & digits*/
		if (!isNumber && line[i] != ' ')
			return (NULL);

		/* the number started */
		if (isNumber)
		{
			foundANumber = 1;
			start = i;
		}
	}
	/* a line of only spaces after the word */
	return (NULL);
}
