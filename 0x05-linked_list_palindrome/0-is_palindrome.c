#include "lists.h"

/**
check_position: check value of give position
@head: pointer to the head of list
@position: position of node
Return: Value of given node
**/

int check_position(listint_t **head, int position) {
	listint_t *current = *head;
	int count = 1;
	while (count <= position) {
		current = current->next;
		count ++;
	}
	return (current->n);
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
	int node = 1;
	int valor = 0;
	int count = 1;

	if (*head == NULL) {
		return (1);
	}

	while (current->next != NULL) {
		node += 1;
		current = current->next;
	}

	if (init->n != current->n) {
		return (0);
	}

	while (count <= node) {
		valor = check_position(&temp, node - count);
		if (init->n != valor) {
			return (0);
		}

		init = init-> next;
		count ++;
	}
	return (1);
}
