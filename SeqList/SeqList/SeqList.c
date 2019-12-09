#include"SeqList.h"

// ˳����ʼ��
void SeqListInit(SeqList* psl, size_t capacity) {
	assert(psl);	//���Խṹ��ָ�벻Ϊ��
	psl->array = NULL;
	psl->size = 0;
	psl->capicity = 0;
}
// ˳�������
void SeqListDestory(SeqList* psl) {
	assert(psl);
	free(psl->array);
	psl->array = NULL;
	psl->capicity = psl->size = 0;

}
// ˳����ӡ
void SeqListPrint(SeqList* psl) {
	size_t i = 0;
	for (i = 0; i < psl->size; ++i)
	{
		printf("%d \n",(psl->array++));
	}
}
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl) {
	assert(psl);
	size_t newcapacity = psl->capicity;
	if (psl->capicity >= psl->size) {
		;
	}
	else
	{
		if (newcapacity == 0)
			newcapacity = 4;
		else
		{
			newcapacity = psl->capicity * 2;
		}
		psl->array = (SLDataType*)realloc(psl->array, newcapacity * sizeof(SLDataType));
		psl->capicity = newcapacity;
		/* size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		 ps->a = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
		 ps->capacity = newcapacity;*/
	}
}
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x) {
	assert(psl);
	void CheckCapacity(SeqList* psl);
	psl->array[psl->size] = x;
	psl->size++;
	
}
// ˳���βɾ
void SeqListPopBack(SeqList* psl) {
	assert(psl);
	psl->array[psl->size] = NULL;
	psl->size--;	
}
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x) {
	assert(psl);
	void CheckCapacity(SeqList* psl);
	while (psl->size )
	{
		psl->array[psl->size + 1] = psl->array[psl->size];
		--psl->size;
	}
	psl->array[psl->size] = x;
}
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl) {
	assert(psl);
	if (psl->size);
	else
	{
		size_t start =0;
		while (start < psl->size)
		{
			psl->array[start] = psl->array[start + 1];
			++start;
		}
		--psl->size ;
		--psl->capicity;
	}
}
// ˳������
int SeqListFind(SeqList* psl, SLDataType x) {
	size_t start = 0;
	size_t end = sizeof(psl) / sizeof(psl->array[0]) - 1;
	size_t mid = (size_t)(start + end) / 2;
	while (start<=end) {
		if (psl->array[mid] > x)
			mid = end;
		if (psl->array[mid] < x)
			mid = start;
		if (psl->array[mid] < x) {
			return psl->array[mid];
			break;
		}
		++start;
		--end;
	}
}
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x) {
	assert(psl);
	void CheckCapacity(SeqList* psl);


}
void TestSeqList() {
	SeqList* psl;
	SeqListInit(&psl, 10);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 2);
	SeqListPushFront(&psl, 3);
	SeqListPushFront(&psl, 4);

	 SeqListPrint(& psl);

}