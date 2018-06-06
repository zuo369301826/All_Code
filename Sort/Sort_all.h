#pragma once
#ifndef _SORT_ALL_H_
#define _SORT_ALL_H_

// 插入排序 
// 直接插入排序 
void InsertSort(int* array, int size);
// 插入排序使用二分进行优化 
void InsertSort_OP(int* array, int size);
// 希尔排序 
void ShellSort(int* array, int size);



// 选择排序 
void SelectSort(int* array, int size);
// 使用每次找最大最小元素对选择排序进行优化 
void SelectSort_OP(int* array, int size);

// 堆调整 向下调整 
void HeapAdjust(int* array, int size, int parent);
// 堆排序 
void HeapSort(int* array, int size);


// 交换排序 
// 冒泡排序 
void BubbleSort(int* array, int size);

// 快速排序 
// 三数取中法 
int GetMidDataIndex(int* array, int left, int right);
// Horn版本分离数据 
int partion1(int* array, int left, int right);
// 挖坑法 
int partion2(int* array, int left, int right);
// 前后指针 
int partion3(int* array, int left, int right);
// 递归实现快速排序 
void QuickSort(int* array, int left, int right);
// 非递归实现快速排序 
void QuickSortNor(int* array, int left, int right);

//归并排序 
// 二路并归，将两组有序的数组合并成一组有序数组 
void MergeData(int* array, int left, int mid, int right, int* temp);
// 归并排序 递归实现 
void MergeSrot(int* array, int size);
// 非递归归并排序 
void MergeSortNor(int* array, int size);


// 非比较排序 

// 计数排序 
void CountSort(int* array, int size);


// 基数排序--低关键码优先 
void RadixSortLSD(int* array, int size);
// 高关键码优先 
void RadixSortMSD(int* array, int size);


void swap(int *data1, int *data2);

void Print(int* array, int size);

#endif