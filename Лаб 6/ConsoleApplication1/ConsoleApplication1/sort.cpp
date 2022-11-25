#include "sort.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void print_array(int arr[], const int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << "\t";
	cout << "\n";
}

void swap(int* a, int* b)
{
	int s = *a;
	*a = *b;
	*b = s;
}

int partition(int arr[], const int p, const int r)
{
	const int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; ++j)
	{
		if (arr[j] < x)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return i + 1;
}

int randomized_partition(int arr[], const int p, const int r)
{
	srand(time(nullptr));
	const int random = p + rand() % (r - p);
	swap(&arr[random], &arr[r]);

	return partition(arr, p, r);
}

void quick_sort(int arr[], const int p, const int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q + 1, r);
	}
}

void quick_sort_r(int arr[], const int p, const int r)
{
	if (p < r)
	{
		int q = randomized_partition(arr, p, r);
		quick_sort_r(arr, p, q - 1);
		quick_sort_r(arr, q + 1, r);
	}
}

int randomized_select(int arr[], const int p, const int r, const int i)
{
	if (p == r)
	{
		return arr[p];
	}
	const int q = randomized_partition(arr, p, r);
	const int k = q - p + 1;
	if (i == k)
	{
		return arr[q];
	}
	if (i < k)
	{
		return randomized_select(arr, p, q - 1, i);
	}
	
	return randomized_select(arr, q + 1, r, i - k);

}
