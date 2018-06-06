// �ǱȽ����� 
#include <assert.h>
#include <math.h>

int FindMax(int *array, int size)
{
	assert(array);

	int max  = array[0];

	int i = 1;

	while (i < size)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		i++;
	}

	return max;
}

int FindMin(int *array, int size)
{
	assert(array);

	int min = array[0];

	int i = 1;

	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		i++;
	}

	return min;
}

//  ****************************************************************** 1.�������� 
void CountSort(int* array, int size)
{
	int max = FindMax(array, size);
	int min = FindMin(array, size);

	int* butter = (int*)malloc(sizeof(int) * (max - min + 1));

	for (int i = 0; i < (max - min + 1); i++)
		butter[i] = 0;

	for (int i = 0; i < size; i++)
	{
		butter[array[i] - min]++;
	}

	int n = 0;
	for (int i = 0; n < size && i < (max - min  + 1); i++)
	{
		for (int j = 0;j < butter[i]; j++)
		{
			array[n++] = (min + i);
		}
	}
	
}



// ******************************************************************** 2.��������--�͹ؼ������� 




void _RadixSortLSD(int* array, int* Butter,int size, int rood)
{
	int count[10] = { 0 };

	for (int i = 0; i < size; i++)//ͳ��ÿ��Ͱ���ݸ���
	{
		count[array[i] / (int)pow((double)10, (double)rood) % 10]++;
	}

	int addr[10] = { 0 };//��ַ

	for (int i = 1; i < size; i++)//ͳ��ÿ��ͨ��ʼ��ַ
	{
		addr[i] = count[i - 1] + addr[i - 1];
	}

	for (int i = 0; i < size; i++)//��������
	{
		Butter[addr[array[i] / (int)pow((double)10, (double)rood) % 10]++] = array[i];
	}

	memcpy(array, Butter, sizeof(int)*size);
}
int FindTime(int *array, int size)
{
	int max = FindMax(array, size);

	int count = 0;
		
	while (max > 0)
	{
		max /= 10;
		count++;
	}
	return count;
}

void RadixSortLSD(int* array, int size)
{
	assert(array);

	int *Butter = (int *)malloc(sizeof(int) * size);

	assert(Butter);

	int rood = FindTime(array, size);

	
	for(int i=0; i< rood; i++ )
	{
		_RadixSortLSD(array, Butter, size, i);
	}

	free(Butter);

}



// ******************************************************************* 2.2 �߹ؼ������� 

//����������
void _RadixSortMSD(int *array, int *Butter, int start, int size, int root)
{
	if (root >= 0)
	{
		int count[10] = { 0 };

		for (int i = 0; i < size; i++)
		{
			count[(int)(array[i] / pow(10, root)) % 10]++;
		}

		int addr[10] = { 0 };

		int addr_start[10] = { 0 };

		for (int i = 1; i < 10; i++)//ͳ��ÿ��ͨ��ʼ��ַ
		{
			addr[i] = count[i - 1] + addr[i - 1];
			addr_start[i] = addr[i];
		}

		for (int i = start; i < size; i++)//��������
		{
			Butter[addr[array[i] / (int)pow((double)10, (double)root) % 10]++] = array[i];
		}

		memcpy(array + start, Butter + start, sizeof(int)*size);
	
		for (int i = 0; i < 10; i++)
		{
			if (count[i] > 1)
				_RadixSortMSD(array, Butter, addr_start[i], count[i], root - 1);
		}
		memcpy(array + start, Butter + start, sizeof(int)*size);
	}
}


void RadixSortMSD(int* array, int size)
{
	assert(array);

	int *Butter = (int *)malloc(sizeof(int) * size);

	assert(Butter);

	int rood = FindTime(array, size);


	_RadixSortMSD(array, Butter,0,size, rood-1);

	free(Butter);
}