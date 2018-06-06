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

// ��ʼ��ջ 
void StackInit(Stack* s);

// ѹջ 
void StackPush(Stack* s, DataType data);

// ��ջ 
void StackPop(Stack* s);

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* s);

// ��ȡջ��Ԫ�ظ��� 
int StackSize(Stack* s);

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(Stack* s);


#endif //_STACK_H_