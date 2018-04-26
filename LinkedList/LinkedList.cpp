#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(const DataType& data)
	: _pNext(NULL)
	, _pPre(NULL)
	, _data(data)
{}

//构造函数
List::List()
	: _pHead(new Node)
{}

//拷贝构造函数
List::List(const List& l)
	:_pHead(new Node)
{
	Node *pCur = l._pHead->_pNext;
	
	while (pCur)
	{
		this->PushBack(pCur->_data);
		pCur = pCur->_pNext;
	}
}

//赋值运算符重载
List& List::operator=(const List& l)
{
	if (&l == this)
		return *this;

	List temp;

	Node *pCur = l._pHead->_pNext;
	while (pCur)
	{
		temp.PushBack(pCur->_data);
		pCur = pCur->_pNext;
	}

	swap(&_pHead, &(temp._pHead));

	return *this;
}

//析构函数
List::~List()
{
	Node *pNext = _pHead->_pNext;
	Node *pDel = _pHead->_pNext;

	while (pDel)
	{
		pNext = pDel->_pNext;
		delete pDel;
		pDel = pNext;
	}

	if(NULL != _pHead)
 	delete _pHead;
	_pHead = NULL;
}

//尾插
void List::PushBack(DataType data)
{
	Node* pCur = _pHead;

	Node* pNode = new Node(data);

	while (pCur->_pNext)
		pCur = pCur->_pNext;

	pNode->_pPre = pCur;
	pCur->_pNext = pNode;	
}
//尾删
void List::PopBack()
{
	if (!Empty())
	{
		Node *pCur = _pHead->_pNext;

		while (pCur->_pNext)
			pCur = pCur->_pNext;

		pCur->_pPre->_pNext = NULL;

		delete pCur;
	}
}
//头插
void List::PushFront(DataType data)
{
	Node *pNode = new Node(data);

	if (Empty())
	{
		_pHead->_pNext = pNode;
		pNode->_pPre = _pHead;
		pNode->_pNext = NULL;
	}
	else
	{
		pNode->_pNext = _pHead->_pNext;

		pNode->_pNext->_pPre = pNode;

		_pHead->_pNext = pNode;
	}
}
//头删
void List::PopFront()
{
	if (!Empty())
	{
		Node* pDel = _pHead->_pNext;

		_pHead->_pNext = pDel->_pNext;

		if(pDel->_pNext)
			pDel->_pNext->_pPre = _pHead;

		if (NULL != pDel)
			delete pDel;
	}
}
//任意位置的插入
void List::Insert(Node* pos, DataType data)
{
	if (pos != NULL)
	{
		Node* temp = new Node(pos->_data);

		temp->_pNext = pos->_pNext;

		temp->_pPre = pos;

		if (pos->_pNext != NULL)
			pos->_pNext->_pPre = temp;

		pos->_pNext = temp;
		pos->_data = data;
	}
}
//任意位置的删除
void List::Erase(Node* pos)
{
	if (NULL != pos)
	{
		if (pos->_pNext)
			pos->_pNext->_pPre = pos->_pPre;
		pos->_pPre->_pNext = pos->_pNext;
		delete pos;
	}
}
//大小
size_t List::Size()
{
	size_t count = 0;
	
	Node* pCur = _pHead;

	while (pCur->_pNext)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//判断链表是否为空
bool List::Empty()const
{
	if (_pHead->_pNext == NULL)
		return true;
	else return false;
}

Node* List::Find(DataType data)
{
	Node* pCur = _pHead->_pNext;
	while (pCur)
	{
		if (pCur->_data == data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}


void List::swap(Node **a1, Node **a2)
{
	Node *temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}


ostream& operator<<(ostream& out, List& l)
{
	out << "pHead ->";
	Node *pCur = l._pHead->_pNext;
	while (pCur)
	{
		out << " <- " << pCur->_data << " -> ";
		pCur = pCur->_pNext;
	}
	out << "NULL";
	return out;
}