#include "lists.h"

/**
list_reverse: Reverses a linked list nodes
@head: pointer to the head of list
Return: Value of given node
**/

listint_t *list_reverse(listint_t *head) {
	listint_t *current = head;
	listint_t *j = head;
	listint_t *prev = NULL;

	while (j) {
		j = current->next;
		current->next = prev;
		prev = current;
		current = j;
	}
	return (prev);
}

/**
is_palindrome - function in C that checks if a singly linked list is a palindrome.
@head: pointer a the head list
Return: 0 if it is not a palindrome, 1 if it is a palindrome
**/

int is_palindrome(listint_t **head) {
	listint_t *current = *head;
	listint_t *init = *head;
	listint_t *temp = *head;
	listint_t *i;

	if (*head == NULL) {
		return (1);
	}

	while (current && temp->next && temp->next->next) {
		init = init->next;
		temp = temp->next->next;
	}
	i = list_reverse(init);
	while(i && current) {
		if (i->n != current->n) {
			return (0);
		}
		i = i->next;
		current = current->next;
	}
	return(1);

	// if (init->n != current->n) {
	// 	return (0);
	// }

	// while (count <= node) {
	// 	valor = list_reverse(&temp, node - count);
	// 	if (init->n != valor) {
	// 		return (0);
	// 	}

	// 	init = init-> next;
	// 	count ++;
	// }
	// return (1);
}
