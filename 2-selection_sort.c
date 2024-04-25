#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using Selection Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        /* Swap the found minimum element with the first element */
        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;

        /* Print the array after each swap */
        print_array(array, size);
    }
}
