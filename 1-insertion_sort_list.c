#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		prev = current->prev;

		while (prev != NULL && prev->n > tmp->n)
		{
			if (prev->prev != NULL)
				prev->prev->next = tmp;
			if (tmp->next != NULL)
				tmp->next->prev = prev;
			tmp->prev = prev->prev;
			prev->next = tmp->next;
			tmp->next = prev;
			prev->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;
			prev = tmp->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
