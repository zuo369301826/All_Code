#include "SeqList.h"
#include <string.h>
#include <iostream>
using namespace std;


SeqList::SeqList(size_t capacity)//���캯��
	:_array (new DataType[capacity]),
	 _size(0),
	 _capacity(capacity)
{ }
SeqList::SeqList(const SeqList& s)//��������
	: _array(new DataType[s._capacity]),
	 _size(s._size),
	_capacity(s._capacity)
{
	memcpy(_array, s._array,sizeof(DataType)*_size);
}
SeqList& SeqList::operator=(const SeqList& s)//��ֵ���������
{
	_size = s._size;
	_capacity = s._capacity;

	//����һ�����ռ䣺
	SeqList temp(s);
	swap(&_array, &temp._array);
	
	return *this;
}
SeqList::~SeqList()//��������
{
	if (_array != NULL)
		delete[] _array;
	_array = NULL;
}

void SeqList::PushBack(DataType data)//β��
{
	//����
	CheckCapacity();

	_array[_size++] = data;
}
void SeqList::PopBack()//βɾ
{
	if(_size > 0)
		_size--;
}
void SeqList::Insert(size_t pos, DataType data)//����λ�ò���
{
	CheckCapacity();
	size_t index = _size++;
	while (index > pos)
	{
		_array[index] = _array[index - 1];
		index--;
	}
	_array[pos] = data;
}

void SeqList::Erase(size_t pos)//����λ��ɾ��
{
	--_size;
	while (pos < _size)
	{
		_array[pos] = _array[pos+1];
		pos++;
	}
}

int SeqList::Size()const//˳����С
{
	return _size;
}
int SeqList::Capacity()const//˳���ռ��С
{
	return _capacity;
}
bool SeqList::Empty()const//�Ƿ�Ϊ��
{
	return _size == 0;
}

DataType& SeqList::operator[](size_t index)//[]����������
{
	if (index < _size)
		return _array[index];
}
const DataType& SeqList::operator[](size_t index)const//[]����������
{
	if (index < _size)
		return (const DataType)_array[index];
}

void SeqList::CheckCapacity() 
{
	if (_size >= _capacity)
	{
		SeqList temp(_capacity + 10);
		_capacity += 10;
		memcpy(temp._array, _array, sizeof(DataType)*_size);
		swap(&_array, &(temp._array));
	}
}
void SeqList::swap(DataType **p1, DataType **p2)
{
	DataType *tem;
	tem = *p1;
	*p1 = *p2;
	*p2 = tem;
}
void SeqList::print()
{
	int index = 0;
	cout << this <<": ";
	while (index < _size)
	{
		cout << _array[index++] << " ";
	}
	cout << endl;
}
