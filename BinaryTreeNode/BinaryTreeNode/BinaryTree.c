#include"BinaryTree.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) 
{
	if (a[*pi] == '#')
	{
		return NULL;
	}
	else
	{
		BTNode * root = (BTNode*)malloc(sizeof(BTNode));
		root-> _data = a[*pi];
		printf("%c ", root->_data);
		++(*pi);
		root->_left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, n, pi);
		return root;
	}
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return ;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
//void BinaryTreeLevelOrder(BTNode* root)
//{
//
//}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	int a= BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right,k-1);
	return a;
	
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}

//�����������
int BinaryTreedepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int a = BinaryTreedepth(root->_left);
	int b = BinaryTreedepth(root->_right);
	return a > b ? a + 1 : b + 1;

}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return  BinaryTreeLeafSize(root->_left)+
	 BinaryTreeLeafSize(root->_right);
	
} 



test() 
{
	char arr[100] = "ABD##E#H##CF##G##";
	int n = strlen(arr);
	int i = 0;
	BTNode * root = BinaryTreeCreate(arr, n,&i);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	char x;
	scanf("%c", &x);
	root = BinaryTreeFind(root, x);
	if (root == NULL)
		printf("%c���ڶ�������\n",x);
	else
		printf("%c�ڶ�������\n", x);
	
	printf("%d\n",BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root,4));
	printf("%d\n", BinaryTreedepth(root));

}