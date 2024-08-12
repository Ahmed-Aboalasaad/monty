#include "monty.h"

/**
 * push - pushes an integer value to the given stack
 *
 * @head: pointer to the head pointer of the doubly linked list
 * that represents the stack
 * @n: the line number that
*/
void push(stack_t **head, unsigned int n)
{
	// stack_t *new;

	// if (!head)
	// 	return;
	// new = malloc(sizeof(*new));
	// if (!new)
	// {
	// 	printf("Error: malloc failed\n");
	// 	exit(EXIT_FAILURE);
	// }
	// new->n = n;
	// new->prev = NULL;
	// if (*head)
	// {
	// 	new->next = *head;
	// 	(*head)->prev = new;
	// }
	// *head = new;

	(void) head;
	(void) n;
	printf("Push was called :)]\n");
}
