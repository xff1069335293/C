#define _CRT_SECURE_NO_WARNINGS 1
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。



示例 1：



输入：[1, 1, 1, 1, 1, null, 1]
输出：true
示例 2：



输入：[2, 2, 2, 5, 2]
输出：false


bool isUnivalTree(struct TreeNode* root) {
	if (root != NULL)
	{
		if (root->left != NULL)
			if (root->val != root->left->val)
				return false;
		if (root->right != NULL)
			if (root->val != root->right->val)
				return false;

		if (!isUnivalTree(root->left) || !isUnivalTree(root->right))
			return false;
	}
	return true;
}