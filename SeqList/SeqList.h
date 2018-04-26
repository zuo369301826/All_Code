#pragma once

typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10);
	SeqList(const SeqList& s);
	SeqList& operator=(const SeqList& s);
	~SeqList();

	void PushBack(DataType data);
	void PopBack();
	void Insert(size_t pos, DataType data);
	void Erase(size_t pos);

	int Size()const;
	int Capacity()const;
	bool Empty()const;

	DataType& operator[](size_t index);
	const DataType& operator[](size_t index)const;

	void swap(DataType **p1, DataType **p2);
	void print();


private:
	void CheckCapacity();

	DataType* _array;
	size_t _size;
	size_t _capacity;
};
