#include "monty.h"

/**
 * pall - prints all the values in the given stack starting from the top.
 *
 * @head: pointer to the head pointer of the doubly linked list
 * that represents the stack
 * @n: dummy parameter needed for opcodes generalization
 * Return: nothing
*/
void pall(stack_t **head, unsigned int n)
{
	(void) n;
	if (!head)
		return;
	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}
