#include"SeqList.h"
#include <iostream>
using namespace std;

int main()
{
	//���캯������
	SeqList List1;
	SeqList List2(3);

	//�������캯������
	SeqList List3(List2);
	

	//β��
	cout << "-------β�����:" << endl;
	List1.PushBack(1);
	List1.print();
	List1.PushBack(2);
	List1.print();
	List1.PushBack(3);
	List1.print();
	List1.PushBack(4);
	List1.print();

	//��ֵ���������
	cout << "-------��ֵ��������ز���:" << endl;
	SeqList List4;
	List4.print();
	List4 = List1;
	List4.print();

	//βɾ
	cout << "-------βɾ����:" << endl;
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


	//����λ�ò���
	cout << "-------λ�ò�����ԣ�" << endl;
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

	//����λ��ɾ��
	cout << "-------����λ��ɾ����" << endl;
	List1.Erase(0);	List1.print();
	List1.Erase(1);	List1.print();
	List1.Erase(2);	List1.print();
	List1.Erase(3);	List1.print();
	List1.Erase(4);	List1.print();
	List1.Erase(5);	List1.print();
	List1.Erase(6);	List1.print();

	//[]���������
	cout << "-------[]��������أ�" << endl;
	List1[0] = 100;
	List1.print();

	const SeqList C_L1(List1);
	const DataType a = C_L1[0];
	cout << "a:" << a << endl;

	return 0;  
}