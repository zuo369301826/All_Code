#include <assert.h>
#include <windows.h>
#include <stdio.h>
#include "Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* s)
{
	assert(s);
	s->_size = 0;
}

// ѹջ 
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_size >= 10)
	{
		return;
	}
	else
	{
		s->_array[s->_size] = data;
		s->_size++;
	}
}

// ��ջ 
void StackPop(Stack* s)
{
	assert(s);
	if (s->_size > 0)
	{
		s->_size--;
	}
}

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* s)
{
	if (s->_size > 0)
	{
		return s->_array[(s->_size) - 1];
	}
}

// ��ȡջ��Ԫ�ظ��� 
int StackSize(Stack* s)
{
	return s->_size;
}

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(Stack* s)
{
	if (s->_size == 0)
	{
		return 1;
	}
	else return 0;
}

