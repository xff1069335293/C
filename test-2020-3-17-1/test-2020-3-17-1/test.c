//.给定一个二叉树，返回它的 后序 遍历。
输/*入[1,null,2,3]
输出[3，2，1]*/
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

void _postorderTraversal(struct TreeNode* root, int *ret, int* returnSize)
{
	if (root == NULL)
	{
		return;
	}
	_postorderTraversal(root->left, ret, returnSize);
	_postorderTraversal(root->right, ret, returnSize);
	ret[(*returnSize)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = treesize(root);
	int* ret = (int*)malloc(sizeof(int)*size);
	*returnSize = 0;
	_postorderTraversal(root, ret, returnSize);
	return ret;
}
