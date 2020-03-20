#define _CRT_SECURE_NO_WARNINGS 1
//.题目描述
//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
//输入描述 :
//输入包括1行字符串，长度不超过100。
//输出描述 :
//可能有多组测试数据，对于每组数据，
//输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。
//每个输出结果占一行。
//示例1
//输入
//复制
//abc##de#g##f###
//输出
//复制
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
