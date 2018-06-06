// 选择排序 

#include "Sort_all.h"


//######################################################################  1.1 直接选择排序
//直接选择排序
//直接选择排序的时间复杂度为O(n^2)； 
//它是一种不稳定的排序算法
void SelectSort(int* array, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int min_ = i;
		for (int j = i+1; j < size ; j++)
		{
			if (array[j] < array[min_])
			{
				min_ = j;
			}
		}
		if (min_ != i)
		{
			array[min_] ^= array[i];
			array[i] ^= array[min_];
			array[min_] ^= array[i];
		}
	}
}

//###################################################################  1.2 直接选择排序优化
// 使用每次找最大最小元素对选择排序进行优化 
void SelectSort_OP(int* array, int size)
{
	for (int i = 0; i < size/2; i++)
	{
		int max_ = i;
		int min_ = i;
		for (int j = i + 1; j < size - i; j++)//寻找最小的和最大的数据
		{
			if (array[max_] < array[j])
				max_ = j;
			if (array[min_] > array[j])
				min_ = j;
		}
		if (min_ != i)//交换最小的数据
		{
			if (max_ == i)//这里有一个问题，如果最小值要交换的位置刚好是最大值得位置，那么就要改变最大值得位置，确保max_所在的值为最大值
				max_ = min_;
			swap(&array[min_], &array[i]);
		}

		if(max_ != size - 1 - i)//交换最大的数据
			swap(&array[max_], &array[size-1-i]);
	}
}


//###################################################################  2.堆排序
//堆排序的时间复杂度为：O(n*log_n)
//堆排序是一种不稳定的排序算法

// 堆调整 向下调整 
void HeapAdjust(int* array, int size, int parent)
{
	int Lchild = parent * 2 + 1;
	int Rchild = Lchild + 1;
	while (Lchild < size)
	{
		if (Rchild < size && array[Rchild] < array[Lchild])
			Lchild = Rchild;
		if (array[Lchild] < array[parent])
		{
			swap(&array[Lchild], &array[parent]);
			parent = Lchild;
			Lchild = parent * 2;
			Rchild = Lchild + 1;
		}
		else
			break;
	}
}

// 堆排序 
void HeapSort(int* array, int size)
{
	//建堆
	int parent = (size - 2) >> 1;//时间复杂度：n/2 * log_n

	for (; parent >= 0; parent--)
	{
		HeapAdjust(array, size, parent);
	}

	//排序
	while (--size)// 时间复杂度：n * log_n
	{
		swap(&array[0], &array[size]);
		HeapAdjust(array, size, 0);
	}
}