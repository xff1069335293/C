//设计循环队列
#define _CRT_SECURE_NO_WARNINGS 1
typedef struct {
	int *que;
	int front;
	int rear;
	int length;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *q1;
	q1 = malloc(sizeof(MyCircularQueue));
	q1->que = malloc(sizeof(int) * (k + 1));
	q1->front = q1->rear = 0;
	q1->length = k + 1;
	return q1;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if ((obj->rear + 1) % (obj->length) == obj->front)
		return false;
	else
	{
		obj->rear = (obj->rear + 1) % (obj->length);
		obj->que[obj->rear] = value;
		return true;
	}
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return false;
	else
	{
		obj->front = (obj->front + 1) % (obj->length);
		return true;
	}
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return -1;
	return obj->que[(obj->front + 1) % obj->length];

}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return -1;
	return obj->que[obj->rear];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->rear == obj->front)
		return true;
	return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->rear + 1) % (obj->length) == obj->front)
		return true;
	return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	int *tmp;
	tmp = obj->que;
	obj->que = NULL;
	free(tmp);
}