#pragma once

#ifndef _STACK_H_
#define _STACK_H_

#define DataType int 
#define MAX_SIZE 10 

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;

// 初始化栈 
void StackInit(Stack* s);

// 压栈 
void StackPush(Stack* s, DataType data);

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
DataType StackTop(Stack* s);

// 获取栈中元素个数 
int StackSize(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);


#endif //_STACK_H_