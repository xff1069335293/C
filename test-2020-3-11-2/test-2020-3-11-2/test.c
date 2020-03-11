//·­×ªÒ»¿Ã¶þ²æÊ÷¡£



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



	struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}
