//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������

//�����У�һ�ø߶�ƽ�����������Ϊ��
//
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
//
//ʾ�� 1:
//
//����������[3, 9, 20, null, null, 15, 7]
//
//3
/// \
//9  20
/// \
//15   7
//���� true ��
//
//ʾ�� 2:
//
//����������[1, 2, 2, 3, 3, null, null, 4, 4]
//
//1
/// \
//2   2
/// \
//3   3
/// \
//4   4
//���� false ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int treedeep(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int a = treedeep(root->left);
	int b = treedeep(root->right);
	return a > b ? a + 1 : b + 1;
}
void max(int*p1, int*p2)
{
	if (*p2 > *p1)
	{
		int tmp = *p2;
		*p2 = *p1;
		*p1 = tmp;
	}
}
bool isBalanced(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	int a = treedeep(root->left);
	int b = treedeep(root->right);
	max(&a, &b);
	return (a - b <= 1) && isBalanced(root->left) && isBalanced(root->right);
}