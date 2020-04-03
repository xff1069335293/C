#include"BinaryTree.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return ;
	}
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return ;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return ;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{	//通过队列，等到入NULL时，看NULL后面有没有非NULL的情况，有就是不是完全二叉树，直到全部出队，就是完全二叉树。
	assert(root);
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (QueueEmpty(&q) != 0)
	{
		BTNode* front = QueueFront(&q);

		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (QueueEmpty(&q) != 0)
	{
		if (QueueFront(&q) == NULL)
		{
			QueuePop(&q);
		}
		else
		{
			return 0;
		}
	}
	return 1;
	QueueDestroy(&q);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(root);
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

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	assert(root);
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

//二叉树的深度
int BinaryTreedepth(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}

	int a = BinaryTreedepth(root->_left);
	int b = BinaryTreedepth(root->_right);
	return a > b ? a + 1 : b + 1;

}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	assert(root);
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

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

// 队头出队列
void QueuePop(Queue* q)
{
	assert(q&& q->_front);
	//只有一个元素 需要将队尾也置空
	//两个 
	if (q->_front->_pNext == NULL)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else
	{
		QNode* next = q->_front->_pNext;
		free(q->_front);
		q->_front = next;
	}

}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (q->_rear == NULL)
	{
		q->_front = q->_rear = newnode;
	}
	else
	{
		q->_rear->_pNext = newnode;
		q->_rear = newnode;
	}
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	QNode* cur = q->_front;
	while (cur)
	{
		++count;
		cur = cur->_pNext;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}



test() 
{
	char arr[100] = "ABC##DE#G##F###";
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
	BinaryTreeLevelOrder(root);
	printf("\n");
	if (BinaryTreeComplete(root) == 0)
	{
		printf("不是完全二叉树\n");
	}
	else
	{
		printf("是完全二叉树\n");
	}
	
	char x;
	scanf("%c", &x);
	root = BinaryTreeFind(root, x);
	if (root == NULL)
		printf("%c不在二叉树中\n",x);
	else
		printf("%c在二叉树中\n", x);
	
	printf("%d\n",BinaryTreeSize(root));	//所有节点
	printf("%d\n", BinaryTreeLeafSize(root));//叶子节点
	printf("%d\n", BinaryTreeLevelKSize(root,4));//K层节点
	printf("%d\n", BinaryTreedepth(root));//深度

}