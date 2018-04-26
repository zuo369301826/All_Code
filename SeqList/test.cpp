#include"SeqList.h"
#include <iostream>
using namespace std;

int main()
{
	//构造函数测试
	SeqList List1;
	SeqList List2(3);

	//拷贝构造函数测试
	SeqList List3(List2);
	

	//尾插
	cout << "-------尾插测试:" << endl;
	List1.PushBack(1);
	List1.print();
	List1.PushBack(2);
	List1.print();
	List1.PushBack(3);
	List1.print();
	List1.PushBack(4);
	List1.print();

	//赋值运算符重载
	cout << "-------赋值运算符重载测试:" << endl;
	SeqList List4;
	List4.print();
	List4 = List1;
	List4.print();

	//尾删
	cout << "-------尾删测试:" << endl;
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();
	List1.PopBack();
	List1.print();

	
	List1.PushBack(1);
	List1.PushBack(2);
	List1.PushBack(3);
	List1.PushBack(4);


	//任意位置插入
	cout << "-------位置插入测试：" << endl;
	List1.print();
	List1.Insert(2, 10);
	List1.print();
	List1.Insert(1, 20);
	List1.print();
	List1.Insert(0, 30);
	List1.print();
	List1.Insert(3, 40);
	List1.print();
	List1.Insert(4, 50);
	List1.print();
	List1.Insert(6, 60);
	List1.print();

	//任意位置删除
	cout << "-------任意位置删除：" << endl;
	List1.Erase(0);	List1.print();
	List1.Erase(1);	List1.print();
	List1.Erase(2);	List1.print();
	List1.Erase(3);	List1.print();
	List1.Erase(4);	List1.print();
	List1.Erase(5);	List1.print();
	List1.Erase(6);	List1.print();

	//[]运算符重载
	cout << "-------[]运算符重载：" << endl;
	List1[0] = 100;
	List1.print();

	const SeqList C_L1(List1);
	const DataType a = C_L1[0];
	cout << "a:" << a << endl;

	return 0;  
}