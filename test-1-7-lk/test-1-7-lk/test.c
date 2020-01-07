//�����������ֵܽڵ�
//�ڶ������У����ڵ�λ����� 0 ����ÿ�����Ϊ k �Ľڵ���ӽڵ�λ����� k+1 ����
//
//����������������ڵ������ͬ�������ڵ㲻ͬ����������һ�����ֵܽڵ㡣
//
//���Ǹ����˾���Ψһֵ�Ķ������ĸ��ڵ� root���Լ�����������ͬ�ڵ��ֵ x �� y��
//
//ֻ����ֵ x �� y ��Ӧ�Ľڵ������ֵܽڵ�ʱ���ŷ��� true�����򣬷��� false��
//
//



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isCousins(struct TreeNode* root, int x, int y)
{
	struct TreeNode *Queue[1000], *present = NULL;
	int front = -1, rear = -1, last = 0, level = 1;
	int signal[2] = { 0 }, father[2] = { 0 };//��¼�������Ĳ�����˫�׽���λ��
	int i = 0, j = 0;
	if (root == NULL)
	{
		return false;
	}
	Queue[++rear] = root;
	while (front < rear)
	{
		present = Queue[++front];
		if (present->left != NULL)
		{
			Queue[++rear] = present->left;
			if (present->left->val == x || present->left->val == y)
			{
				signal[i] = level;
				father[j] = front;
				i++;
				j++;
			}
		}
		if (present->right != NULL)
		{
			Queue[++rear] = present->right;
			if (present->right->val == x || present->right->val == y)
			{
				signal[i] = level;
				father[j] = front;
				i++;
				j++;
			}
		}
		if (front == last)
		{
			level++;
			last = rear;
		}
	}
	if (signal[0] == signal[1] && father[0] != father[1])
	{
		return true;
	}
	else
	{
		return false;
	}
}