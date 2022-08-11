#include "lists.h"
/**
 * insert_node - function, inserts a number into a sorted singly linked list.
 * @head: double pointer to head of linked list
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *current_node = NULL;

	if (head == NULL)
		return (NULL);
	current_node = *head;
	new_node = malloc(sizeof(listint_t));
	new_node->n = number;
	new_node->next = NULL;
	if (current_node == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (number < current_node->n)
	{
		new_node->next = current_node;
		*head = new_node;
		return (new_node);
	}
	while (current_node->next && current_node->next->n <= number)
		current_node = current_node->next;
	new_node->next = current_node->next;
	current_node->next = new_node;
	return (new_node);
}
