#include "sort.h"

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: Array to be partitioned
 * @low: The first index of the partition
 * @high: The last index of the partition
 * @size: No. of elements in the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the Quick sort algorithm
 * @array: Array to be sorted
 * @low: The first index of the partition
 * @high: The last index of the partition
 * @size: No. of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pIndex;

	if (low < high)
	{
		pIndex = lomuto_partition(array, low, high, size);
		quicksort(array, low, pIndex - 1, size);
		quicksort(array, pIndex + 1, high, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Array to be sorted
 * @size: No. of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
