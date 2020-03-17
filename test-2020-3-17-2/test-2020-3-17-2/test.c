//给定一个二叉树，返回它的中序 遍历。
//输入[1,null,2,3]
//输出[1,3,2]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int treesize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + treesize(root->left) + treesize(root->right);
}

void _inorderTraversal(struct TreeNode* root, int *ret, int* returnSize)
{
	if (root == NULL)
	{
		return;
	}
	_inorderTraversal(root->left, ret, returnSize);
	ret[(*returnSize)++] = root->val;
	_inorderTraversal(root->right, ret, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = treesize(root);
	int* ret = (int*)malloc(sizeof(int)*size);
	*returnSize = 0;
	_inorderTraversal(root, ret, returnSize);
	return ret;
}
