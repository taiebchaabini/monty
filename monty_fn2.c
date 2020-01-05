#include "monty.h"
/**
 * add_dnodeint - unction that adds a new node at the beginning of
 * a dlistint_t list.
 * @head: dlistint_t header pointer to pointer
 * @n: new value to insert in the new node
 * Return: adress of the new element or NULL if it failed
 **/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	(*head)->prev = new;
	new->next = *head;
	*head = new;
	return (new);
}
