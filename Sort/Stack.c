#include <assert.h>
#include <windows.h>
#include <stdio.h>
#include "Stack.h"

// 初始化栈 
void StackInit(Stack* s)
{
	assert(s);
	s->_size = 0;
}

// 压栈 
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

// 出栈 
void StackPop(Stack* s)
{
	assert(s);
	if (s->_size > 0)
	{
		s->_size--;
	}
}

// 获取栈顶元素 
DataType StackTop(Stack* s)
{
	if (s->_size > 0)
	{
		return s->_array[(s->_size) - 1];
	}
}

// 获取栈中元素个数 
int StackSize(Stack* s)
{
	return s->_size;
}

// 检测栈是否为空 
int StackEmpty(Stack* s)
{
	if (s->_size == 0)
	{
		return 1;
	}
	else return 0;
}

