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
	assert(root);
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
	assert(root);
	if (root == NULL)
	{
		return ;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// �������������
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

// �������
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

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{	//ͨ�����У��ȵ���NULLʱ����NULL������û�з�NULL��������о��ǲ�����ȫ��������ֱ��ȫ�����ӣ�������ȫ��������
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

// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
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

//�����������
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

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// ������Ҷ�ӽڵ����
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

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q&& q->_front);
	//ֻ��һ��Ԫ�� ��Ҫ����βҲ�ÿ�
	//���� 
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

// ��β�����
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

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ���
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}

// ���ٶ���
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
		printf("������ȫ������\n");
	}
	else
	{
		printf("����ȫ������\n");
	}
	
	char x;
	scanf("%c", &x);
	root = BinaryTreeFind(root, x);
	if (root == NULL)
		printf("%c���ڶ�������\n",x);
	else
		printf("%c�ڶ�������\n", x);
	
	printf("%d\n",BinaryTreeSize(root));	//���нڵ�
	printf("%d\n", BinaryTreeLeafSize(root));//Ҷ�ӽڵ�
	printf("%d\n", BinaryTreeLevelKSize(root,4));//K��ڵ�
	printf("%d\n", BinaryTreedepth(root));//���

}