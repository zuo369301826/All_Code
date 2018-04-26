#pragma once
#include <iostream>
using namespace std;
typedef int DataType;

struct Node
{
	Node* _pNext;
	Node* _pPre;
	DataType _data;

	Node(const DataType& data = DataType());
};

class List
{
public:
	List();
	List(const List& l);
	List& operator=(const List& l);
	~List();

	void PushBack(DataType data);
	void PopBack();
	void PushFront(DataType data);
	void PopFront();
	void Insert(Node* pos, DataType data);
	void Erase(Node* pos);
	size_t Size();
	bool Empty()const;
	Node* Find(DataType _data);

	void swap(Node **a1, Node **a2);
	friend ostream& operator<<(ostream& cout, List& l);

private:
	Node * _pHead;
};
