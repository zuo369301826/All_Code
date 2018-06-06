#include "Sort_all.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//�鲢���� 

// ��·���飬���������������ϲ���һ���������� 
void MergeData(int* array, int left, int mid, int right, int* temp)
{
	if (right - left < 2)
		return;

	int Lmid = left +( (mid - left) >> 1);
	
	int Rmid = mid + ((right - mid) >> 1);
	
	MergeData(array, left, Lmid , mid, temp);
	
	MergeData(array, mid, Rmid, right, temp);

	int i = left;
	int j = left;
	int k = mid;
	while (j<mid && k<right)
	{
		temp[i++] =(array[j] < array[k])? array[j++] : array[k++];
	}

	while (j < mid)
		temp[i++] = array[j++];
	while (k < right)
		temp[i++] = array[k++];

	memmove(array + left, temp + left, sizeof(int)*(right - left));
}

// �鲢���� �ݹ�ʵ�� 
void MergeSrot(int* array, int size)
{
	int* temp = (int *)malloc(sizeof(int) * size);
	
	assert(temp);

	MergeData(array, 0, size >> 1, size, temp);

	free(temp);
}


// �ǵݹ�鲢���� 
void MergeSortNor(int* array, int size)
{
	assert(array);

	int root = 1;

	int* temp = (int *)malloc(sizeof(int) * size);

	while(root <  size)
	{
		for (int i = 0; i < size; i += 2 * root)
		{
			int mid = i + root;
			if (mid > size)
				mid = size;
			int end = i + 2 * root;
			if (end > size)
				end = size;

			int j = i;
			int left = i;
			int right = mid;

			while (left<mid && right<end)
			{
				temp[j++] = (array[left] < array[right]) ? array[left++] : array[right++];
			}

			while (left < mid)
				temp[j++] = array[left++];
			while (right < end)
				temp[j++] = array[right++];
		}
		memcpy(array, temp, sizeof(int)*(size));
		root *= 2;
	}
}