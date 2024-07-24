#include <iostream>
#include <functional>
#include <vector>

int partition(std::vector<int>& list, int first, int last)
{
	int pivotValue = list[last];
	int pivotIndex = first - 1;

	for (int index = first; index < last; index++)
	{
		if(list[index] < pivotValue)
		{
			pivotIndex++;
			std::swap(list[index], list[pivotIndex]);
		}
	}

	pivotIndex++;
	std::swap(list[pivotIndex], list[last]);
	return pivotIndex;
}

void quick_sort(std::vector<int>& list, int first, int last)
{
	if(first < last)
	{
		int pivotIndex = partition(list, first, last);

		quick_sort(list, first, pivotIndex - 1);
		quick_sort(list, pivotIndex + 1, last);
	}
}

int main()
{
	std::vector<int> list = { 5, 7, 1, 3, 2, 4, 6 };
	int n = list.size();

	quick_sort(list, 0, n - 1);

	for (int num : list)
	{
		std::cout << num << " ";
	}

	return 0;
}