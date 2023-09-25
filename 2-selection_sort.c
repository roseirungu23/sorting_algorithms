#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 * order using Selection sort
 *
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, leastIndex;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		leastIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[leastIndex])
				leastIndex = j;
		}
		if (leastIndex != i)
		{
			tmp = array[i];
			array[i] = array[leastIndex];
			array[leastIndex] = tmp;

			print_array(array, size);
		}
	}
}
