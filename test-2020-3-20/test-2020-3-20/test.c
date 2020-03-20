#define _CRT_SECURE_NO_WARNINGS 1
//.��Ŀ����
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
//�������� :
//�������1���ַ��������Ȳ�����100��
//������� :
//�����ж���������ݣ�����ÿ�����ݣ�
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
//ÿ��������ռһ�С�
//ʾ��1
//����
//����
//abc##de#g##f###
//���
//����
//c b e g d f a


#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode
{
	char _val;
	struct TreeNode* pleft;
	struct TreeNode* pright;
}TreeNode;

TreeNode* CreateTree(char* arr, int *pi)
{
	if (arr[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
		root->_val = arr[*pi];
		++(*pi);
		root->pleft = CreateTree(arr, pi);
		++(*pi);
		root->pright = CreateTree(arr, pi);
		return root;
	}
}
void InorderTraversal(TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}
	InorderTraversal(root->pleft);
	printf("%c ", root->_val);
	InorderTraversal(root->pright);
}

int main()
{
	char arr[100];
	scanf("%s", arr);
	int i = 0;
	TreeNode * root = CreateTree(arr, &i);
	InorderTraversal(root);
	return 0;
}
