#include"banker.h"

void Bankerinit(Node* psl){
	psl->capcity =psl->size=psl->resource=psl->_val= 0;
	psl->_allocation = psl->_available = psl->_max = psl->_need=psl->_work = NULL;
}
void Print() {
	printf("*************************************\n");
	printf("***********1.初始化    **************\n");
	printf("***********2.查看      **************\n"); 
	printf("***********3.请求资源  **************\n");
	printf("***********4.退出      **************\n");
	printf("*************************************\n");
}
void Nodepush(Node* psl, Bdatetype resource, Bdatetype size) {
	psl->resource = resource;//资源数
	psl->size = size;//进程数量
	size_t i ,j= 0;
	for (i = 0; i < size; ++i)
		printf("请输入第%d个进程的资源分配情况\n");
		for (j = 0; j < resource; ++j) {
			printf("请输入第 %d 个最大资源数\n",j);
			scanf("%d ", psl->_max[j]);
			printf("请输入第 %d 个资源分配数\n", j);
			scanf("%d ", psl->_allocation[j]);
			psl->_need[j] = psl->_max[j] - psl->_allocation[j];
			printf("请输入第 %d 个资源可分配数\n", j);
			scanf("%d ", psl->_available[j]);
		}
	

}
test() {
	Node psl;
	Bankerinit(&psl);
}