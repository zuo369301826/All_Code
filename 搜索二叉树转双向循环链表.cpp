#include <iostream>
using namespace std;

//搜索二叉树转化为双向循环链表
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
		if (pRoot == NULL)//空数
		{
			pFirstNode = NULL;//本树的第一个节点为NULL
			pLastNode = NULL;//本树的最后一个节点为NULL
			return;
		}
		
		if (pRoot->left == NULL)
			pFirstNode = pRoot;//左子树不存在，第一个节点就是root
		else 
		{
			//左子树存在
			_Convert(pRoot->left, pFirst_Left, pLast_Left);//继续处理左子树
			pFirstNode = pFirst_Left;//本树的第一个节点就是左子树的第一个节点
			pRoot->left = pLast_Left;//连接本树的左边 -- 左子树的最后一个结点
			pLast_Left->right = pRoot;//使左子树的最后一个结点指向root 
		}

		if (pRoot->right == NULL)
			pLastNode = pRoot;//右子树不存在，最后一个节点就是root
		else
		{
			//右子树存在
			_Convert(pRoot->right, pFirst_Rigth, pLast_Rigth);//继续处理右子树
			pLastNode = pLast_Rigth;//本树的最后一个节点就是右子树最后一个节点
			pRoot->right = pFirst_Rigth;//连接root的右边--右子树第一个节点
			pFirst_Rigth->left = pRoot;//右子树第一个节点指向root
		}
	}
};