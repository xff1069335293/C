#include"banker.h"

void Bankerinit(Node* psl){
	psl->capcity =psl->size=psl->resource=psl->_val= 0;
	psl->_allocation = psl->_available = psl->_max = psl->_need=psl->_work = NULL;
}
void Print() {
	printf("*************************************\n");
	printf("***********1.��ʼ��    **************\n");
	printf("***********2.�鿴      **************\n"); 
	printf("***********3.������Դ  **************\n");
	printf("***********4.�˳�      **************\n");
	printf("*************************************\n");
}
void Nodepush(Node* psl, Bdatetype resource, Bdatetype size) {
	psl->resource = resource;//��Դ��
	psl->size = size;//��������
	size_t i ,j= 0;
	for (i = 0; i < size; ++i)
		printf("�������%d�����̵���Դ�������\n");
		for (j = 0; j < resource; ++j) {
			printf("������� %d �������Դ��\n",j);
			scanf("%d ", psl->_max[j]);
			printf("������� %d ����Դ������\n", j);
			scanf("%d ", psl->_allocation[j]);
			psl->_need[j] = psl->_max[j] - psl->_allocation[j];
			printf("������� %d ����Դ�ɷ�����\n", j);
			scanf("%d ", psl->_available[j]);
		}
	

}
test() {
	Node psl;
	Bankerinit(&psl);
}