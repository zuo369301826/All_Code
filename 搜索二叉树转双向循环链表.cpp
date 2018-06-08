#include <iostream>
using namespace std;

//����������ת��Ϊ˫��ѭ������
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
		}
};

class Solution {
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pFirstNode;
		TreeNode* pLastNode;

		_Convert(pRootOfTree, pFirstNode, pLastNode);

		return pFirstNode;
	}
	void _Convert(TreeNode * pRoot, TreeNode * & pFirstNode, TreeNode * & pLastNode)
	{
		TreeNode * pFirst_Left, *pLast_Left, *pFirst_Rigth, *pLast_Rigth;
		if (pRoot == NULL)//����
		{
			pFirstNode = NULL;//�����ĵ�һ���ڵ�ΪNULL
			pLastNode = NULL;//���������һ���ڵ�ΪNULL
			return;
		}
		
		if (pRoot->left == NULL)
			pFirstNode = pRoot;//�����������ڣ���һ���ڵ����root
		else 
		{
			//����������
			_Convert(pRoot->left, pFirst_Left, pLast_Left);//��������������
			pFirstNode = pFirst_Left;//�����ĵ�һ���ڵ�����������ĵ�һ���ڵ�
			pRoot->left = pLast_Left;//���ӱ�������� -- �����������һ�����
			pLast_Left->right = pRoot;//ʹ�����������һ�����ָ��root 
		}

		if (pRoot->right == NULL)
			pLastNode = pRoot;//�����������ڣ����һ���ڵ����root
		else
		{
			//����������
			_Convert(pRoot->right, pFirst_Rigth, pLast_Rigth);//��������������
			pLastNode = pLast_Rigth;//���������һ���ڵ�������������һ���ڵ�
			pRoot->right = pFirst_Rigth;//����root���ұ�--��������һ���ڵ�
			pFirst_Rigth->left = pRoot;//��������һ���ڵ�ָ��root
		}
	}
};