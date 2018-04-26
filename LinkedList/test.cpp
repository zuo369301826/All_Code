#include "LinkedList.h"


void test1()
{
	//���캯������
	List l1;

	//β�����
	cout << "--------------β����ԣ�" << endl;
	l1.PushBack(1);cout << "l1: " << l1 << endl;
	l1.PushBack(2);cout << "l1: " << l1 << endl;
	l1.PushBack(3);cout << "l1: " << l1 << endl;
	l1.PushBack(4);cout << "l1: " << l1 << endl;
	cout << "l1 �������" << l1.Size() << endl;

	//�������캯������
	cout << "--------------�������캯�����ԣ�" << endl;
	List l2(l1);
	cout << "l2: " << l2 << endl;

	//��ֵ��������ز���
	cout << "--------------��ֵ��������ز��ԣ�" << endl;
	List l3;
	l3 = l1;
	cout <<"l3: "<< l3 << endl;

	//βɾ����
	cout << "--------------βɾ���ԣ�" << endl;
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

	//ͷ�����
	cout << "--------------ͷ����ԣ�" << endl;
	l1.PushFront(1);cout << "l1: " << l1 << endl;
	l1.PushFront(2);cout << "l1: " << l1 << endl;
	l1.PushFront(3);cout << "l1: " << l1 << endl;
	l1.PushFront(4);cout << "l1: " << l1 << endl;
	cout << "l1 �������"<<l1.Size() << endl;

	//ͷɾ����
	cout << "--------------ͷɾ���ԣ�" << endl;
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
	cout << "l1 �������" << l1.Size() << endl;

	//����λ�õĲ������
	cout << "--------------����λ�õĲ�����ԣ�" << endl;
	l1.Insert(l1.Find(1), 10); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(2), 20); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(3), 30); cout << "l1: " << l1 << endl;
	l1.Insert(l1.Find(4), 40); cout << "l1: " << l1 << endl;
	cout << "l1 �������" << l1.Size() << endl;
	//����λ�õ�ɾ������
	cout << "--------------����λ�õ�ɾ�����ԣ�" << endl;
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