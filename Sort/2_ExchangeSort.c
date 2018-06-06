#include "Sort_all.h"
#include <assert.h>
#include "Stack.h"
// ��������


//##########################################################  1 ð������ 
//ð������������ʱ�临�Ӷ�O(n)��ð������������ʱ�临�Ӷ�O(n^2)
//ð������ռ临�Ӷ�O(1)
void BubbleSort(int* array, int size)
{
	int flag = 1;
	for (int i = 0; i < size - 1; i++)
	{
		flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				flag = 0;
				swap(&array[j], &array[j + 1]);
			}
		}
		if (flag == 1)
			break;
	}
}

// ######################################################### 2.�������� 

// ����ȡ�з� 
int GetMidDataIndex(int* array, int left, int right)
{
	assert(array);

	int mid = left + ((right - left) >> 1);

	if (array[left] < array[right])
	{
		if (array[mid] > array[right])
			return right;
		else if (array[mid] < array[left])
			return left;
		else return mid;
	}
	else
	{
		if (array[mid] < array[right])
			return right;
		else if (array[mid] > array[left])
			return left;
		else return mid;
	}
}

// Horn�汾�������� 
int partion1(int* array, int left, int right)
{

	int addr = GetMidDataIndex(array, left, right);

	int key = right;

	if(addr != right)
		swap(&array[addr], &array[right]);

	while (left < right)
	{
		while (left < right && array[left] <= array[key])
			left++;
		while (right > left && array[right] >= array[key])
			right--;
		if(left < right)
		swap(&array[left], &array[right]);
	}

	if(right != key)
		swap(&array[key], &array[right]);

	return right;
}

// �ڿӷ� 
int partion2(int* array, int left, int right)
{
	int addr = GetMidDataIndex(array, left, right);

	if (addr != right)
		swap(&array[addr], &array[right]);

	int key = array[right];

	while (left < right)
	{
		while (left < right && array[left] <= key)
			left++;
		array[right] = array[left];

		while (left < right && array[right] >= key)
			right--;
		array[left] = array[right];
	}

	array[right] = key;

	return right;
}

// ǰ��ָ�� 
int partion3(int* array, int left, int right)
{
	int addr = GetMidDataIndex(array, left, right);

	if (addr != right)
		swap(&array[addr], &array[right]);

	int key=array[right];

	int First = left;
	int Second = left;

	while (First < right)
	{
		if (array[First] <= key)
		{
			if (First == Second)
			{
				First++;
				Second++;
			}
			else
			{
				swap(&array[First++], &array[Second++]);
			}	
		}
		else
		{
			First++;
		}
	}
	if(Second != right)
		swap(&array[Second], &array[right]);
	

	return Second;
}


// �ݹ�ʵ�ֿ��� 
void QuickSort(int* array, int left, int right)//����ұ����䣬rightȡ����,�����������Ϊ�±� left �� right
{
	assert(array);
	
	if (left < right )//��֤���ݴ���һ�������left = right ��ʣ��һ�����ݲ���Ҫ��������leftҪС��right
	{
		//int mid = partion1(array, left, right);
		//int mid = partion2(array, left, right);
		int mid = partion3(array, left, right);

		QuickSort(array, left, mid - 1);//�������  �±�Ϊ left �� mid-1;

		QuickSort(array, mid + 1, right);//�����ұ� �±�Ϊ mid+1 �� right;
	}
}

// �ǵݹ�ʵ�ֿ���
void QuickSortNor(int* array, int left, int right)
{
	assert(array);

	Stack s;
	StackInit(&s);

	if (right > left)
	{
		StackPush(&s, left);
		StackPush(&s, right);
	}

	while (!StackEmpty(&s))
	{
		right = StackTop(&s);
		StackPop(&s);
		left = StackTop(&s);
		StackPop(&s);

		int mid = partion1(array, left, right);
		//int mid = partion2(array, left, right);
		//int mid = partion3(array, left, right);

		if (left < mid - 1)
		{
			StackPush(&s, left);
			StackPush(&s, mid - 1);
		}

		if (mid + 1 < right)
		{
			StackPush(&s, mid + 1);
			StackPush(&s,right);
		}
	}

}
