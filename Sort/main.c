#include <stdio.h>
#include "Sort_all.h"




int main()
{
	int array[] = { 100,9, 3,51, 6, 1, 8,15, 4, 7, 2, 5, 0 ,10, 11, 84, 95,51,50};
	//int array[] = { 9, 3, 6, 1, 8, 4, 7, 2, 5,0};
	//int array[] = { 3,9, 3, 50, 4, 1, 8,4, 4, 7, 2, 50, 0 ,10, 11, 7, 2, 1,50 };
	//int array[] = { 125,458,612,958,655,187,953,126,841,697 };
	//int array[] = { 1233,764,84,4,7,205,548,27,639,836 };

	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);

	//InsertSort(array, size);
	InsertSort_OP(array, size);
	//ShellSort(array, size);
	//SelectSort(array, size);
	//SelectSort_OP(array, size);
	//HeapSort(array, size);
	//BubbleSort(array, size);
	//QuickSort(array, 0, size - 1);
	//QuickSortNor(array, 0, size - 1);
	//MergeSrot(array, size);
	MergeSortNor(array, size);
	//CountSort(array, size);
	//RadixSortLSD(array, size);
	//RadixSortMSD(array,size);

	Print(array, size);
	system("pause");
	return 0;
}