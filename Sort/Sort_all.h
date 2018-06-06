#pragma once
#ifndef _SORT_ALL_H_
#define _SORT_ALL_H_

// �������� 
// ֱ�Ӳ������� 
void InsertSort(int* array, int size);
// ��������ʹ�ö��ֽ����Ż� 
void InsertSort_OP(int* array, int size);
// ϣ������ 
void ShellSort(int* array, int size);



// ѡ������ 
void SelectSort(int* array, int size);
// ʹ��ÿ���������СԪ�ض�ѡ����������Ż� 
void SelectSort_OP(int* array, int size);

// �ѵ��� ���µ��� 
void HeapAdjust(int* array, int size, int parent);
// ������ 
void HeapSort(int* array, int size);


// �������� 
// ð������ 
void BubbleSort(int* array, int size);

// �������� 
// ����ȡ�з� 
int GetMidDataIndex(int* array, int left, int right);
// Horn�汾�������� 
int partion1(int* array, int left, int right);
// �ڿӷ� 
int partion2(int* array, int left, int right);
// ǰ��ָ�� 
int partion3(int* array, int left, int right);
// �ݹ�ʵ�ֿ������� 
void QuickSort(int* array, int left, int right);
// �ǵݹ�ʵ�ֿ������� 
void QuickSortNor(int* array, int left, int right);

//�鲢���� 
// ��·���飬���������������ϲ���һ���������� 
void MergeData(int* array, int left, int mid, int right, int* temp);
// �鲢���� �ݹ�ʵ�� 
void MergeSrot(int* array, int size);
// �ǵݹ�鲢���� 
void MergeSortNor(int* array, int size);


// �ǱȽ����� 

// �������� 
void CountSort(int* array, int size);


// ��������--�͹ؼ������� 
void RadixSortLSD(int* array, int size);
// �߹ؼ������� 
void RadixSortMSD(int* array, int size);


void swap(int *data1, int *data2);

void Print(int* array, int size);

#endif