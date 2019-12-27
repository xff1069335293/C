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
	printf("***********1.����    **************\n");
	printf("***********2.������Դ    ************\n"); 
	printf("***********3.չʾ  **************\n");
	printf("***********4.��ȫ�Լ��� **************\n");
	printf("***********0.�˳�      **************\n");
	printf("*************************************\n");
}
void request(Node* psl, Bdatetype size, Bdatetype resource,Bdatetype input) {  //ִ��������Դ
	size_t j = 0, i = 0;
	int tmp = 0;
	int input1= input - 1; 
	int need[M][N] = { 0 };
	int available[M][N] = { 0 };
	int allocation[M][N] = { 0 };
	printf("��������̵�������Դ��:\n");
	for (j = 0; j < resource; ++j) {
		scanf("%d", &psl->_request[input1][j]);
	}	
	for (j = 0; j < resource; ++j) {		//����һ�������������ͷ���
		if (psl->_request[input1][j] > psl->_need[input1][j])
		{
			printf("�����������\n");
			return;
		}
	}
	for (j = 0; j < resource; ++j) {		//����һ��������ڿ��þͷ���
		if (psl->_request[input1][j] > psl->_available[0][j]) {
			printf("������ڿ���\n");
			return;
		}
	}
										//����������Դ����ȫ����������
		for (j = 0; j < resource; ++j)
		{
			need[input1][j] = psl->_need[input1][j];
			allocation[input1][j] = psl->_allocation[input1][j];
			available[0][j] = psl->_available[0][j];		//�洢���ν��̵����
			psl->_available[0][j] -= psl->_request[input1][j];
			psl->_allocation[input1][j] = psl->_allocation[input1][j] + psl->_request[input1][j];//���±���������̵����
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
	
	if (safetytest(*psl, size, resource) == 0) {				//����ʧ��Ҫ���ոյĽ��������ԭ
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
		printf("����ɹ�\n");
	}
}

int safetytest(Node psl, Bdatetype size, Bdatetype resource) {  //��ȫ�Լ���
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
					if (psl._work[0][j] < psl._need[i][j]) {	//����һ�鲻���������ľ�����ѭ��
						flag = 0;
						break;
					}
				}

				if (flag)
				{		//��flagΪ1ʱ����ʾ���п�����Դ������һ��С��need
					for (j = 0; j < resource; ++j) {
						psl._work[0][j] += psl._allocation[i][j];
					}
					psl._finish[i][0] = 1;  //���˽��̱�עΪtrue
					psl._count[count] = i;		//ͳ�ư�ȫ��������
					++num; //����
					++count;//ͳ�ư�ȫ����
					k = 1;
					break;
				}

			}

		}

		if (k == 0)
		{				//ѭ��һȦ K������Ļ�  
			printf("����ȫ\n");
			return 0;
		}
		k = 0;	//����ʱ��1 ������0  ��Num
	}

	printf("��ȫ����\n");		//�����ȫ���� ��ʱ����һ���ǰ�ȫ
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
//		printf("����ȫ\n");
//		return;
//	}
//	k = 0;
//}
//	printf("��ȫ����\n");
//	for (i = 0; i < size; ++i) {
//		
//		printf("p%d ", psl->_count[i]);
//	}
//	printf("\n");
//}
//
void Nodepush(Node* psl, Bdatetype size, Bdatetype resource) {		//������Դ���
	Bdatetype i ,j= 0;
	
	for (j = 0; j < resource;++j) {
			printf("������� %d ��Դ��sum\n", j + 1);
			scanf("%d", &psl->_sum[0][j]);
		}
	for (i = 0; i < size; ++i) {
		printf("�������%d�����̵���Դ�������\n", i + 1);
		for (j = 0; j < resource; ++j) {
			printf("������� %d ����Դmax��ֵ\n", j + 1);
			scanf("%d", &psl->_max[i][j]);
		}
		for (j = 0; j < resource; ++j) {
			printf("������� %d ����Դallocation��ֵ\n", j + 1);
			scanf("%d", &psl->_allocation[i][j]);
			psl->_need[i][j] = psl->_max[i][j] - psl->_allocation[i][j];
		}
		for (j = 0; j < resource; ++j) {
			psl->_available[0][j] = psl->_sum[0][j] -= psl->_allocation[i][j];
			
		}
	}

}

void Display(Node* psl, Bdatetype size, Bdatetype resource) {//չʾ������Դ���
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
			printf("�����˳�\n");
			break;
		case 1:
			Bankerinit(&psl);
			printf("���������������Դ��\n");
			scanf("%d %d", &size, &resourse);
			Nodepush(&psl, size, resourse);
			break;
		case 2:			
			printf("��������̺�\n");
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
			printf("����������������룺\n");
				break;
		
		}

	} while (input);
	
	Bankerinit(&psl);

}