#include "Sort_all.h"
#include<stdio.h>
void swap(int *data1, int *data2)
{
	*data1 ^= *data2;
	*data2 ^= *data1;
	*data1 ^= *data2;
}

void Print(int* array, int size)
{
	for (int index = 0; index < size; index++)
		printf("%d ", array[index]);
	printf("\n");
}