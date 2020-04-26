//����һ������������, �ҵ�����������ָ���ڵ������������ȡ�
//
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����
//
//���磬�������¶��������� : root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]
//
//
//
//
//
//	ʾ�� 1:
//
//����: root = [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5], p = 2, q = 8
//	��� : 6
//	���� : �ڵ� 2 �ͽڵ� 8 ��������������� 6��

	
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return nullptr;

	if (p->val < root->val && q->val < root->val)
		return lowestCommonAncestor(root->left, p, q);
	if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}