#include"SeqList.h"
// ������ɾ��Ľӿ�
// ˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity) {
	assert(psl);
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}

// ˳�������
void SeqListDestory(SeqList* psl) {
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->size = psl->capicity = 0;
}



// ˳����ӡ
void SeqListPrint(SeqList* psl){
	assert(psl);
	size_t i = 0;
	for (i = 0; i < psl->size; ++i) {
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}


// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl) {
	if (psl->size == psl->capicity)
	{
		size_t newcapacity = psl->capicity== 0 ? 4 : psl->capicity * 2;
		psl->array = (SLDataType*)realloc(psl->array, newcapacity * sizeof(SLDataType));
		psl->capicity = newcapacity;
	}

}


// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x) {
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	++psl->size;
	
}


// ˳���βɾ
void SeqListPopBack(SeqList* psl) {
	psl->array[psl->size] = NULL;
	--psl->size;
	--psl->capicity;
}



// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);


// ˳���ͷɾ
void SeqListPopFront(SeqList* psl);


// ˳������
int SeqListFind(SeqList* psl, SLDataType x);


// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);


// ˳���ɾ��posλ�õ�ֵ
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