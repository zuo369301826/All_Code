// 插入排序 
#include "Sort_all.h"

//############################################################## 1.1 直接插入排序
// 直接插入排序 
//最优情况下：时间效率为O(n)
//最差情况下：时间复杂度为O(n^2)
//空间复杂度：O(1)，它是一种稳定的排序算法
void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = array[i];//存放要插入的数据
		int index = i;
		while (index > 0 && temp < array[index - 1])//查找位置,和前面的数据依次比较，如果比前一个数据小，则将前一个数据后移，继续查找
		{
			array[index] = array[index - 1];//数据后移
			index--;
		}

		if (index != i)
			array[index] = temp;//将要数据插入
	}
}


//############################################################## 1.2  直接插入排序优化 二分法
int _InsertSort_OP(int *array, int left, int right, int data)
{
	if (right > left)
	{
		int mid = left + ((right - left) >>1);

		if (data >= array[mid])
			return _InsertSort_OP(array, mid + 1, right, data);
		else 
			return _InsertSort_OP(array, left, mid , data);
	}
	else return right;
}

// 插入排序使用二分进行优化 
void InsertSort_OP(int* array, int size)
{
	int InsertAddr;

	for (int i = 1; i < size; i++)
	{
		int temp = array[i];

		InsertAddr = _InsertSort_OP(array, 0, i, array[i]);

		if (InsertAddr != i)
		{
			for (int index = i; index > InsertAddr; index--)
				array[index] = array[index - 1];

			array[InsertAddr] = temp;//将要数据插入
		}
	}
}

//###################################################################### 2.希尔排序 
void ShellSort(int* array, int size)
{
	int gap;
	for (gap = size / 2; gap > 0; gap >>= 1)//增量
	{
		for (int i = gap; i < size; i++)//每次增量进行排序，直到增量为1，进行最后一次排序
		{
			int temp = array[i];
			int index = i;
			while (index >= gap && temp < array[index - gap])
			{
				array[index] = array[index - gap];
				index -= gap;
			}

			if (index != i)
				array[index] = temp;		
		}
	}
}