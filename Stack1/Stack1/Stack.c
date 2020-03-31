#include"Stack.h"


// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_capacity == ps->_top)//�������������
	{
		int newcapcity = ps->_capacity == 0 ? 2 : 2 * ps->_capacity;
		ps->_a = (STDataType*)realloc(ps->_a,newcapcity*sizeof(STDataType));
		ps->_capacity = newcapcity;
	}
	ps->_a[ps->_top++] = data;
}


// ��ջ
void StackPop(Stack* ps) 
{
	assert(ps && ps->_top>0);
	--ps->_top;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
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

// ����ջ
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