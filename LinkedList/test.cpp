#include "LinkedList.h"


void test1()
{
	//构造函数测试
	List l1;

	//尾插测试
	cout << "--------------尾插测试：" << endl;
	l1.PushBack(1);cout << "l1: " << l1 << endl;
	l1.PushBack(2);cout << "l1: " << l1 << endl;
	l1.PushBack(3);cout << "l1: " << l1 << endl;
	l1.PushBack(4);cout << "l1: " << l1 << endl;
	cout << "l1 结点数：" << l1.Size() << endl;

	//拷贝构造函数测试
	cout << "--------------拷贝构造函数测试：" << endl;
	List l2(l1);
	cout << "l2: " << l2 << endl;

	//赋值运算符重载测试
	cout << "--------------赋值运算符重载测试：" << endl;
	List l3;
	l3 = l1;
	cout <<"l3: "<< l3 << endl;

	//尾删测试
	cout << "--------------尾删测试：" << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
	l1.PopBack(); cout << "l1: " << l1 << endl;
}


void test2()
{
	List l1;

	//头插测试
	cout << "--------------头插测试：" << endl;
	l1.PushFront(1);cout << "l1: " << l1 << endl;
	l1.PushFront(2);cout << "l1: " << l1 << endl;
	l1.PushFront(3);cout << "l1: " << l1 << endl;
	l1.PushFront(4);cout << "l1: " << l1 << endl;
	cout << "l1 结点数："<<l1.Size() << endl;

	//头删测试
	cout << "--------------头删测试：" << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
	l1.PopFront(); cout << "l1: " << l1 << endl;
}

void test3()
{
	List l1;
	l1.PushBack(1); cout << "l1: " << l1 << endl;
	l1.PushBack(2); cout << "l1: " << l1 << endl;
	l1.PushBack(3); cout << "l1: " << l1 << endl;
	l1.PushBack(4); cout << "l1: " << l1 << endl;
	cout << "l1 结点数：" << l1.Size() << endl;

	//任意位置的插入测试
	cout << "--------------任意位置的插入测试：" << endl;
	l1.Insert(l1.Find(1), 10); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(2), 20); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(3), 30); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(4), 40); cout << "l1: " << l1 << endl;
	cout << "l1 结点数：" << l1.Size() << endl;
	//任意位置的删除测试
	cout << "--------------任意位置的删除测试：" << endl;
	l1.Erase(l1.Find(10)); cout << "l1: " << l1 << endl;
	l1.Erase(l1.Find(20)); cout << "l1: " << l1 << endl;
	l1.Erase(l1.Find(30)); cout << "l1: " << l1 << endl;
	l1.Erase(l1.Find(40)); cout << "l1: " << l1 << endl;
}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}