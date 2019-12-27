#include"banker.h"

void Bankerinit(Node* psl){
	size_t i = 0, j = 0;
	for (i = 0; i < M; ++i) 
		for (j = 0; j < N; ++j) {
			psl->_allocation[i][j] = psl->_available[0][j] = psl->_need[i][j] = psl->_max[i][j]=psl->_work[0][j] =psl->_finish[i][0]=psl->_sum[i][j]=psl->_request[i][j]= 0;
		}

	psl->size=psl->resource= 0;
}
void Print() {
	printf("*************************************\n");
	printf("***********1.输入    **************\n");
	printf("***********2.请求资源    ************\n"); 
	printf("***********3.展示  **************\n");
	printf("***********4.安全性检验 **************\n");
	printf("***********0.退出      **************\n");
	printf("*************************************\n");
}
void request(Node* psl, Bdatetype size, Bdatetype resource,Bdatetype input) {  //执行请求资源
	size_t j = 0, i = 0;
	int tmp = 0;
	int input1= input - 1; 
	int need[M][N] = { 0 };
	int available[M][N] = { 0 };
	int allocation[M][N] = { 0 };
	printf("请输入进程的请求资源数:\n");
	for (j = 0; j < resource; ++j) {
		scanf("%d", &psl->_request[input1][j]);
	}	
	for (j = 0; j < resource; ++j) {		//存在一个请求大于需求就返回
		if (psl->_request[input1][j] > psl->_need[input1][j])
		{
			printf("请求大于需求\n");
			return;
		}
	}
	for (j = 0; j < resource; ++j) {		//存在一个请求大于可用就返回
		if (psl->_request[input1][j] > psl->_available[0][j]) {
			printf("请求大于可用\n");
			return;
		}
	}
										//本次所需资源请求全部符合条件
		for (j = 0; j < resource; ++j)
		{
			need[input1][j] = psl->_need[input1][j];
			allocation[input1][j] = psl->_allocation[input1][j];
			available[0][j] = psl->_available[0][j];		//存储本次进程的情况
			psl->_available[0][j] -= psl->_request[input1][j];
			psl->_allocation[input1][j] = psl->_allocation[input1][j] + psl->_request[input1][j];//更新本次请求进程的情况
			psl->_need[input1][j] = psl->_need[input1][j] - psl->_request[input1][j];
			tmp += psl->_need[input1][j];
			
		}
	if (tmp==0) {
		for (j = 0; j < resource; ++j) {
			psl->_available[0][j] += psl->_allocation[input1][j];
			psl->_allocation[input1][j] = 0;
			psl->_finish[input1][0] = 1;
		}	
	}
	
	if (safetytest(*psl, size, resource) == 0) {				//分配失败要将刚刚的进程情况还原
		for (j = 0; j < resource; ++j)
		{
			psl->_need[input1][j] = need[input1][j];
			psl->_allocation[input1][j] = allocation[input1][j];
			psl->_available[0][j] = available[0][j];
			//psl->_finish[i][0] = 0;
		}
	}
	else
	{	
		printf("分配成功\n");
	}
}

int safetytest(Node psl, Bdatetype size, Bdatetype resource) {  //安全性检验
	size_t j = 0, i = 0, k = 0;
	int flag = 1;
	int count = 0, num = 0;
	for (j = 0; j < resource; ++j)					//work =ava
	{
		psl._work[0][j] = psl._available[0][j];
	}
	for (i = 0; i < size; ++i)						//finish =0
	{
		psl._finish[i][0] = 0;
	}

	while (num < size) {
		for (i = 0; i < size; ++i) {
			flag = 1;
			if (psl._finish[i][0] == 0){
				for (j = 0; j < resource; ++j)
				{
					if (psl._work[0][j] < psl._need[i][j]) {	//存在一组不符合条件的就跳出循环
						flag = 0;
						break;
					}
				}

				if (flag)
				{		//当flag为1时，表示所有可用资源的数量一定小于need
					for (j = 0; j < resource; ++j) {
						psl._work[0][j] += psl._allocation[i][j];
					}
					psl._finish[i][0] = 1;  //将此进程标注为true
					psl._count[count] = i;		//统计安全进程序列
					++num; //计数
					++count;//统计安全序列
					k = 1;
					break;
				}

			}

		}

		if (k == 0)
		{				//循环一圈 K都不变的话  
			printf("不安全\n");
			return 0;
		}
		k = 0;	//成立时置1 后再置0  在Num
	}

	printf("安全序列\n");		//输出安全序列 此时跳出一定是安全
	for (i = 0; i < size; ++i) {
		printf("p%d ", psl._count[i]+1);
	
	}
	printf("\n");
	return 1;
}

//	while (num!=size){
//	for (i = 0; i < size; ++i) {
//		if (!(psl->_finish[i][0])){
//			for (j = 0; j < resource; ++j) {
//				if (psl->_work[0][j] < psl->_need[i][j]) {
//					flag = 0;
//					break;
//				}
//			}
//				if (flag) {
//					for (j = 0; j < resource; ++j) {
//						psl->_work[0][j] = psl->_work[0][j] + psl->_allocation[0][j];
//					}
//					psl->_finish[i][0] = 1;
//					psl->_count[count] = i;
//					++count;
//					++num;
//					k = 1;
//					break;
//				}
//				flag = 1;
//			}
//		
//	}
//	if (k == 0) {
//		printf("不安全\n");
//		return;
//	}
//	k = 0;
//}
//	printf("安全序列\n");
//	for (i = 0; i < size; ++i) {
//		
//		printf("p%d ", psl->_count[i]);
//	}
//	printf("\n");
//}
//
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
			printf("%d  ", psl->_work[0][j]);
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
			printf("%d  ", psl->_available[0][j]);
		}
		printf("|");

		for (j = 0; j < resource; ++j) {
			printf("%d  ", psl->_finish[i][0]);
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
			printf("程序退出\n");
			break;
		case 1:
			Bankerinit(&psl);
			printf("请输入进程数和资源数\n");
			scanf("%d %d", &size, &resourse);
			Nodepush(&psl, size, resourse);
			break;
		case 2:			
			printf("请输入进程号\n");
			int input1 = 0;
			scanf("%d", &input1);
			request(&psl, size, resourse, input1);
			break;

		case 3:
			Display(&psl, size, resourse);
			break;
		
		case 4:
			safetytest(psl, size, resourse);
			break;

		default:
			printf("输入错误，请重新输入：\n");
				break;
		
		}

	} while (input);
	
	Bankerinit(&psl);

}