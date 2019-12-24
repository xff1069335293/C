//用栈实现队列

typedef struct {
	int front;
	int rear;
	int val[10000];
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(int) * 10002);
	obj->front = obj->rear = 0;
	memset(obj->val, 0, sizeof(int) * 10000);
	return obj;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	obj->val[obj->rear] = x;
	(obj->rear)++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int tmp = obj->val[obj->front];
	obj->val[obj->front] = 0;
	(obj->front)++;
	return tmp;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	return obj->val[obj->front];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return (obj->front == obj->rear);
}

void myQueueFree(MyQueue* obj) {
	obj->front = obj->rear = 0;
	memset(obj->val, 0, sizeof(int) * 10000);
}