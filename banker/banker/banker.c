#include"banker.h"

void Bankerinit(Node* psl){
	size_t i = 0, j = 0;
	for (i = 0; i < M; ++i) 
		for (j = 0; j < N; ++j) {
			psl->_allocation[i][j] = psl->_available[i][j] = psl->_need[i][j] = psl->_max[i][j]=psl->_work[i][j] =psl->_finish[i][j]=psl->_sum[i][j]= 0;
		}
	
	/*psl->_allocation[][]=0
	psl->_available= (Bdatetype*)malloc(sizeof(Bdatetype) * 4);
	psl->_max= (Bdatetype*)malloc(sizeof(Bdatetype) * 4);
	psl->_need=(Bdatetype*)malloc(sizeof(Bdatetype) * 4);
	psl->_work= (Bdatetype*)malloc(sizeof(Bdatetype) * 4);
	if (psl->_allocation&&psl->_available&&psl->_max&&psl->_need==NULL)
	{
		printf("内存分配失败\n");
	}*/
	psl->size=psl->resource= 0;
}
void Print() {
	printf("*************************************\n");
	//printf("***********1.初始化	    **************\n");
	printf("***********1.输入    **************\n");
	printf("***********2.请求资源    ************\n"); 
	printf("***********3.展示  **************\n");
	printf("***********4.安全性检验 **************\n");
	printf("***********0.退出      **************\n");
	printf("*************************************\n");
}
void request(Node* psl, Bdatetype size, Bdatetype resource,Bdatetype input) {  //执行请求资源
	size_t j = 0, i = 0;
	i = input - 1; 
	printf("请输入需要资源请求的进程数：\n");
	for (j = 0; j < resource; ++j) {
		printf("请输入第 %d 个资源的请求资源数:\n",j+1);
		scanf("%d", &psl->_request[i][j]);
	}	
		for (j = 0; j < resource; ++j) {
			if (psl->_request[i][j] <= psl->_need[i][j]) {
				if (psl->_request[i][j]<=psl->_available[0][j])
				{	
					if (psl->_request[i][j] >=psl->_need[i][j])
					{
						psl->_available[i][j] = psl->_available[0][j] - psl->_request[i][j] + psl->_max[i][j];
					}
					else
					{
						psl->_available[i][j] = psl->_available[0][j] - psl->_request[i][j];
					}
						psl->_allocation[i][j] = psl->_allocation[i][j] + psl->_request[i][j];
						psl->_need[i][j] = psl->_need[i][j] - psl->_request[i][j];
						printf("分配成功\n");
						break;
				}
				else
					printf("可以分配资源不足，分配失败\n");
				break;
			}
			else
			{
				printf("请求失败，超过所需资源的最大值\n");
				break;
			}
		}
}

void safetytest(Node* psl, Bdatetype size, Bdatetype resource, Bdatetype input) {  //安全性检验
	size_t j = 0, i = 0, k = 0;
	int flag = 1;
	int count = 0,num=0;
	//for (j = 0; j < resource; ++j)		//work =ava
	//{
	//	psl->_work[0][j] = psl->_available[0][j];
	//}
	//for (i = 0; i < size; ++i) //finish =0
	//{
	//	psl->_finish[i][0] = 0;
	//}
	//for (i = 0; i < size; ++i) {
	//	if (psl->_finish[i][0]==0) {
	//		for (j = 0; i < resource; ++j) {
	//			if (psl->_need[i][j] <= psl->_work[0][j]) {

	//			}

	//		}
	//	}
	//}

	while (num!=size){

	for (i = 0; i < size; ++i) {
		
		if (!(psl->_finish[i][0])) {
			for (j = 0; j < resource; ++j) {
				if (psl->_work[0][j] < psl->_need[i][j]) {
					flag = 0;
					break;
				}
			}
				if (flag) {
					for (j = 0; j < resource; ++j) {
						psl->_work[0][j] = psl->_work[0][j] + psl->_allocation[0][j];
					}
					psl->_finish[i][0] = 1;
					psl->_count[count] = i;
					++count;
					++num;
					k = 1;
					break;
				}
				flag = 1;
			}
		
	}
	if (k == 0) {
		printf("不安全\n");
		return;
	}
	k = 0;
}
	printf("安全序列\n");
	for (i = 0; i < size; ++i) {
		
		printf("p%d ", psl->_count[i]);
	}
	printf("\n");
}
void Nodepush(Node* psl, Bdatetype size, Bdatetype resource) {		//输入资源情况
	Bdatetype i ,j= 0;
	
	for (j = 0; j < resource;++j) {
			printf("请输入第 %d 资源的sum\n", j + 1);
			scanf("%d", &psl->_sum[0][j]);
		}
	for (i = 0; i < size; ++i) {
		printf("请输入第%d个进程的资源分配情况\n", i + 1);
		for (j = 0; j < resource; ++j) {
			printf("请输入第 %d 个资源max的值\n", j + 1);
			scanf("%d", &psl->_max[i][j]);
		}
		for (j = 0; j < resource; ++j) {
			printf("请输入第 %d 个资源allocation的值\n", j + 1);
			scanf("%d", &psl->_allocation[i][j]);
			psl->_need[i][j] = psl->_max[i][j] - psl->_allocation[i][j];
		}
		for (j = 0; j < resource; ++j) {
			psl->_available[0][j] = psl->_sum[0][j] -= psl->_allocation[i][j];
			
		}
	}

}

void Display(Node* psl, Bdatetype size, Bdatetype resource) {//展示各个资源情况
	size_t i, j = 0;
	printf("| pid |work|max|allocation|need|available|finish\n");
	for (i = 0; i < size; ++i) {
		printf("|");
		printf("P%d ", i + 1);
		printf("|");
		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_work[i][j]);
		}
		printf("|");
		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_max[i][j]);
		}
		printf("|");
		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_allocation[i][j]);
		}
		printf("|");
		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_need[i][j]);
		}
		printf("|");
		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_available[i][j]);
		}
		printf("|");

		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_finish[i][j]);
		}
		printf("|");
		printf("\n");
	}
}
	

void test() {
	Node psl;
	Bdatetype input=0,size=0,resourse=0;
	do
	{
		Print();
		scanf("%d",&input);
		switch (input) {
		case 0:
			break;
		case 1:
			Bankerinit(&psl);
			printf("请输入进程数和资源数\n");
			scanf("%d %d", &size, &resourse);
			Nodepush(&psl, size, resourse);
			break;
		case 2:
			printf("请输入进程号\n");
			input = 0;
			scanf("%d", &input);
			request(&psl, size, resourse, input);
			break;

		case 3:
			Display(&psl, size, resourse);
			break;
		
		case 4:
			safetytest(&psl, size, resourse, input);
			break;

		default:
			printf("输入错误，请重新输入：\n");
				break;
		
		}

	} while (input);
	
	Bankerinit(&psl);

}