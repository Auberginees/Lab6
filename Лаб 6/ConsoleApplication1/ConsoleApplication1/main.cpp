#include "sort.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	int size;
	cout << "Введiть розмiр масиву\n";
	cin >> size;
	const auto arr = new int[size];
	cout << "Введiть елементи масиву\n";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	cout << "Ваш масив \n";
	print_array(arr, size);
	while (1)
	{
		cout << "\n1. Швидке сортування\n2. Випадкове швидке сортування\n3. Випадкова вибiрка\nВаш вибiр: ";
		int n;
		cin >> n;
		do
		{
			switch (n)
			{
			case 1:
				quick_sort(arr, 0, size - 1);
				break;
			case 2:
				quick_sort_r(arr, 0, size - 1);
				break;
			case 3:
				randomized_select(arr, 0, size - 1, rand() % size + 1);
				break;
			}
			cout << "\nВiдсортований масив \n";
			print_array(arr, size);
			int min = arr[0];
			int max = arr[0];
			for (int i = 0; i < size; ++i)
			{
				if (max < arr[i])
					max = arr[i];
			}
			for (int i = 0; i < size; ++i)
			{
				if (min > arr[i])
					min = arr[i];
			}
			cout << "\nМiнiмум = " << min;
			cout << "\nМаксимум = " << max;
			if (size % 2 == 1)
			{
				cout << "\nМедiана = " << arr[size / 2];

			}
			else cout << "\nМедiана = " << (arr[size / 2 - 1]) << "," << (arr[size / 2]);
			break;
		} while (n > 0 && n <= 3);
	}
}
