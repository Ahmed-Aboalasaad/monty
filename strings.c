#include "monty.h"

/**
 * isEqual - check if the given string are identical
 *
 * @s1: the first string
 * @s2: the second string
 * Return: 1 if they're identical, 0 otherwise
*/
char isEqual(char *s1, char *s2)
{
	int i, len1, len2;

	if (!s1 || !s2)
		return (0);

	/* Check Lengths */
	for (i = len1 = 0; s1[i]; i++)
		len1++;
	for (i = len2 = 0; s2[i]; i++)
		len2++;
	if (len2 != len1)
		return (0);

	/* Check Values */
	for (i = 0; i < len1; i++)
		if (s1[i] != s2[i])
			return (0);

	/* passed the tests */
	return (1);
}

/**
 * strSlice - takes a slice of the given string
 *
 * @s: the string to extract a slice from
 * @start: the starting index (included)
 * @end: the ending index (included)
 * Return: a copy of the required slice, or NULL if it fails
*/
char *strSlice(char *s, unsigned int start, unsigned int end)
{
    char *new;
    int i;

    if (start > end)
        return (NULL);

    new = malloc(sizeof(char) * (end - start + 2));
    if (!new)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new[end - start + 1] = '\0';
    for (i = 0; i + start <= end; i++)
    {
        if (!s[i])
        {
            printf("Error: slicing end is out of boundary\n");
            free(new);
            return (NULL);
        }
        new[i] = s[i + start];
    }
    return (new);
}

int strLen(char *s)
{
    int i;

    for (i = 0; s[i]; )
        i++;
    return (i);
}

unsigned int strToInt(char *s)
{
    int result, i;

    if (!s)
        return (0);
    for (result = i = 0; s[i]; i++)
    {
        result *= 10;
        result += s[i] - '0';
    }
    return (result);
}
