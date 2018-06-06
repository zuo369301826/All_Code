// ѡ������ 

#include "Sort_all.h"


//######################################################################  1.1 ֱ��ѡ������
//ֱ��ѡ������
//ֱ��ѡ�������ʱ�临�Ӷ�ΪO(n^2)�� 
//����һ�ֲ��ȶ��������㷨
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

//###################################################################  1.2 ֱ��ѡ�������Ż�
// ʹ��ÿ���������СԪ�ض�ѡ����������Ż� 
void SelectSort_OP(int* array, int size)
{
	for (int i = 0; i < size/2; i++)
	{
		int max_ = i;
		int min_ = i;
		for (int j = i + 1; j < size - i; j++)//Ѱ����С�ĺ���������
		{
			if (array[max_] < array[j])
				max_ = j;
			if (array[min_] > array[j])
				min_ = j;
		}
		if (min_ != i)//������С������
		{
			if (max_ == i)//������һ�����⣬�����СֵҪ������λ�øպ������ֵ��λ�ã���ô��Ҫ�ı����ֵ��λ�ã�ȷ��max_���ڵ�ֵΪ���ֵ
				max_ = min_;
			swap(&array[min_], &array[i]);
		}

		if(max_ != size - 1 - i)//������������
			swap(&array[max_], &array[size-1-i]);
	}
}


//###################################################################  2.������
//�������ʱ�临�Ӷ�Ϊ��O(n*log_n)
//��������һ�ֲ��ȶ��������㷨

// �ѵ��� ���µ��� 
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

// ������ 
void HeapSort(int* array, int size)
{
	//����
	int parent = (size - 2) >> 1;//ʱ�临�Ӷȣ�n/2 * log_n

	for (; parent >= 0; parent--)
	{
		HeapAdjust(array, size, parent);
	}

	//����
	while (--size)// ʱ�临�Ӷȣ�n * log_n
	{
		swap(&array[0], &array[size]);
		HeapAdjust(array, size, 0);
	}
}