//给定一个二叉树，检查它是否是镜像对称的。



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
	bool judgemirror(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	if (left == NULL || right == NULL)
	{
		return false;
	}
	if (left->val != right->val)
	{
		return false;
	}
	return judgemirror(left->left, right->right) &&
		judgemirror(left->right, right->left);

}

bool isSymmetric(struct TreeNode* root)
{
	if (root == NULL)
	{
		return true;
	}
	return judgemirror(root->left, root->right);
}
