#define _CRT_SECURE_NO_WARNINGS 1
//���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
//
//ʾ�� 1:
//�������� s :
//
//3
/// \
//4   5
/// \
//1   2
//�������� t��
//
//4
/// \
//1   2
//���� true����Ϊ t �� s ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��
//
//ʾ�� 2:
//�������� s��
//
//3
/// \
//4   5
/// \
//1   2
///
//0
//�������� t��
//
//4
/// \
//1   2
//���� false��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSame(struct TreeNode* s, struct TreeNode* t)
{
	if (s == NULL && t == NULL)
	{
		return true;
	}
	if (s == NULL || t == NULL)
	{
		return false;
	}
	if (s->val != t->val)
	{
		return false;
	}
	return isSame(s->left, t->left) && isSame(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{

	if (s == NULL)
	{
		return false;
	}

	return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}