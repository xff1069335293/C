#include"Stack.h"


// 初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_top)//检查容量，扩容
	{
		int newcapcity = ps->_capacity == 0 ? 2 : 2 * ps->_capacity;
		ps->_a = (STDataType*)realloc(ps->_a,newcapcity*sizeof(STDataType));
		ps->_capacity = newcapcity;
	}
	ps->_a[ps->_top++] = data;
}


// 出栈
void StackPop(Stack* ps) 
{
	assert(ps && ps->_top>0);
	--ps->_top;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPop(&s);
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (StackEmpty(&s) != 0)
	{
		printf("%d ",StackTop(&s));
		StackPop(&s);
	}
	StackDestroy(&s);
}