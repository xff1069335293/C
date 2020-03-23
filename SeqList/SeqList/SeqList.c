#include"SeqList.h"

//顺序表初始化
void SeqListInit(SeqList* psl)
{
	assert(psl);
	psl->arr = NULL;
	psl->capacity = 0;
	//psl->arr = (SLDataType*)malloc(sizeof(SLDataType)*(psl->capacity));
	psl->size = 0;
}

// 顺序表销毁
void SeqListDestory(SeqList* psl) 
{
	assert(psl);
	free(psl->arr);
	psl->arr = NULL;
	psl->capacity = 0;
	psl->size = 0;
}

// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	for (size_t i = 0; i<psl->size; i++)
	{

		printf("%d ",psl->arr[i]);
	}
	printf("\n");
}

// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		int newcapacity = psl->capacity == 0 ? 2 : 2 * psl->capacity;
		psl->arr = (SLDataType*)realloc(psl->arr, newcapacity*sizeof(SLDataType));//注意realloc 的使用时，后面为字节数
		psl->capacity = newcapacity;
	}
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}

// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->size--;
}

// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	int num = psl->size++;
	while (num)
	{
		psl->arr[num] = psl->arr[num - 1];
		--num;
	}
	psl->arr[num] = x;
}

// 顺序表头删
void SeqListPopFront(SeqList* psl)
{	
	assert(psl);
	size_t num = 0;
	while (num<psl->size-1)
	{
		psl->arr[num] = psl->arr[num+1]; //注意不要越界访问
		++num;
	}
	psl->size--;
}

// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t num = psl->size;
	while (num >= 0 && psl->arr[num] != x)
	{
		--num;
	}
	return num;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos < psl->size);
	CheckCapacity(psl);
	size_t num = psl->size++;
	while (num > pos)
	{
		psl->arr[num] = psl->arr[num-1];
		--num;
	}
	psl->arr[pos] = x;

}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos) 
{
	assert(psl);
	assert(pos<psl->size);
	size_t num = pos;
	while (num<psl->size)
	{
		psl->arr[num] = psl->arr[num+1];
		++num;
	}
	psl->size--;
}
void test()
{
	SeqList psl;
	SeqListInit(&psl);
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPrint(&psl);
	SeqListPopBack(&psl);
	SeqListPrint(&psl);
	SeqListPushFront(&psl, 0);
	SeqListPushFront(&psl, 1);
	SeqListPrint(&psl);
	SeqListPopFront(&psl);
	SeqListPopFront(&psl);
	SeqListPrint(&psl);
	SeqListInsert(&psl,2, 4);
	SeqListInsert(&psl,0, -1);
	SeqListPrint(&psl);
	SeqListErase(&psl, 0);
	SeqListPrint(&psl);
	int ret = SeqListFind(&psl, 0);
	if (ret < 0)
		printf("没找到该数字\n");
	else
		printf("找到该数字,下标为-> %d\n", ret);
	SeqListDestory(&psl);
	SeqListPrint(&psl);
}