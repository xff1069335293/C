#include"SeqList.h"
// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity) {
	assert(psl);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}

// 顺序表销毁
void SeqListDestory(SeqList* psl) {
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->size = psl->capicity = 0;
}



// 顺序表打印
void SeqListPrint(SeqList* psl){
	assert(psl);
	size_t i = 0;
	for (i = 0; i < psl->size; ++i) {
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}


// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl) {
	if (psl->size == psl->capicity)
	{
		size_t newcapacity = psl->capicity== 0 ? 4 : psl->capicity * 2;
		psl->array = (SLDataType*)realloc(psl->array, newcapacity * sizeof(SLDataType));
		psl->capicity = newcapacity;
	}

}


// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x) {
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	++psl->size;
	
}


// 顺序表尾删
void SeqListPopBack(SeqList* psl) {
	psl->array[psl->size] = NULL;
	--psl->size;
	--psl->capicity;
}



// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);


// 顺序表头删
void SeqListPopFront(SeqList* psl);


// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);


// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);


// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);


void TestSeqList(){
	SeqList psl;
	SeqListInit(&psl, 10);
	SeqListPushBack(&psl,1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPopBack(&psl);
	 SeqListPrint(&psl);

}