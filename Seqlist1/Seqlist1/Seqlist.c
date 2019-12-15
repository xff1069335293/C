#include"SeqList.h"
// 基本增删查改接口
void SeqListInit(SeqList* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}

	printf("\n");
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->size);

	//size_t start = pos;
	//while (start < ps->size-1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}

	size_t start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}

	ps->size--;
}

void CheckCacpity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	//assert(ps);
	//CheckCacpity(ps);

	//ps->a[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	/*CheckCacpity(ps);

	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}

	ps->a[0] = x;
	++ps->size;*/

	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	/*size_t start = 0;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	size_t start = 1;
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		++start;
	}

	--ps->size;*/
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);

	CheckCacpity(ps);

	//int end = ps->size - 1;
	//while (end >= (int)pos)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}

	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}


	ps->a[pos] = x;
	ps->size++;
}





void TestSeqList() {
	SeqList psl;
	SeqListInit(&psl);
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPopBack(&psl);
	SeqListPushFront(&psl, 6);
	//SeqListDestory(&psl);
	SeqListPrint(&psl);

}