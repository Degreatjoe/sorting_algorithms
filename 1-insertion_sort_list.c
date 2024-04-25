#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion Sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;

    while (current != NULL)
    {
        listint_t *insertion_point = current->prev;
        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            /* Swap current node with the insertion point */
            if (insertion_point->prev != NULL)
                insertion_point->prev->next = current;
            if (current->next != NULL)
                current->next->prev = insertion_point;

            insertion_point->next = current->next;
            current->prev = insertion_point->prev;

            current->next = insertion_point;
            insertion_point->prev = current;

            /* If insertion point was head, update head */
            if (current->prev == NULL)
                *list = current;

            /* Move insertion point backwards */
            insertion_point = current->prev;

            /* Print the list after each swap */
            print_list(*list);
        }
        /* Move to the next node */
        current = current->next;
    }
}
