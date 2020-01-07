//二叉树的堂兄弟节点
//在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
//
//如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
//
//我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
//
//只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
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
	int signal[2] = { 0 }, father[2] = { 0 };//记录两个结点的层数及双亲结点的位置
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