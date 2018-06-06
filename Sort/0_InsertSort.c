// �������� 
#include "Sort_all.h"

//############################################################## 1.1 ֱ�Ӳ�������
// ֱ�Ӳ������� 
//��������£�ʱ��Ч��ΪO(n)
//�������£�ʱ�临�Ӷ�ΪO(n^2)
//�ռ临�Ӷȣ�O(1)������һ���ȶ��������㷨
void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = array[i];//���Ҫ���������
		int index = i;
		while (index > 0 && temp < array[index - 1])//����λ��,��ǰ����������αȽϣ������ǰһ������С����ǰһ�����ݺ��ƣ���������
		{
			array[index] = array[index - 1];//���ݺ���
			index--;
		}

		if (index != i)
			array[index] = temp;//��Ҫ���ݲ���
	}
}


//############################################################## 1.2  ֱ�Ӳ��������Ż� ���ַ�
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

// ��������ʹ�ö��ֽ����Ż� 
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

			array[InsertAddr] = temp;//��Ҫ���ݲ���
		}
	}
}

//###################################################################### 2.ϣ������ 
void ShellSort(int* array, int size)
{
	int gap;
	for (gap = size / 2; gap > 0; gap >>= 1)//����
	{
		for (int i = gap; i < size; i++)//ÿ��������������ֱ������Ϊ1���������һ������
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