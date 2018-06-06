#include "Sort_all.h"
#include <assert.h>
#include "Stack.h"
// 交换排序


//##########################################################  1 冒泡排序 
//冒泡排序最好情况时间复杂度O(n)，冒泡排序最坏情况下时间复杂度O(n^2)
//冒泡排序空间复杂度O(1)
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

// ######################################################### 2.快速排序 

// 三数取中法 
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

// Horn版本分离数据 
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

// 挖坑法 
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

// 前后指针 
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


// 递归实现快排 
void QuickSort(int* array, int left, int right)//左闭右闭区间，right取不到,即处理的数据为下标 left 到 right
{
	assert(array);
	
	if (left < right )//保证数据大于一个，如果left = right 即剩下一个数据不需要处理，所以left要小于right
	{
		//int mid = partion1(array, left, right);
		//int mid = partion2(array, left, right);
		int mid = partion3(array, left, right);

		QuickSort(array, left, mid - 1);//处理左边  下标为 left 到 mid-1;

		QuickSort(array, mid + 1, right);//处理右边 下标为 mid+1 到 right;
	}
}

// 非递归实现快排
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
