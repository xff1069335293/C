//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//	ʾ����
//	����������[3, 9, 20, null, null, 15, 7]��
//
//	�������������� 3 ��
//	

	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     struct TreeNode *left;
	 *     struct TreeNode *right;
	 * };
	 */


	int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int a = 1 + maxDepth(root->left);
	int b = 1 + maxDepth(root->right);
	return a > b ? a : b;
}
