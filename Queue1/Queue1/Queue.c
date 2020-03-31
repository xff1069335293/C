#include"Queue.h"


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
	assert(q);
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
	QNode* newnode =(QNode* )malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (q->_rear == NULL)
	{
		q->_front=q->_rear = newnode;
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


void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueEmpty(&q) != 0)
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
}