#include"proceeding.h"
struct Node
{
	char name;//������
	int Tarrive;//����ʱ��
	int Tservice;//����ʱ��	
	int Tsurplus;//ʣ��ʱ��
	int Tstart;//��ʼʱ��
	int Taccomplish;//���ʱ��
	int prio;//���ȼ�
	int if_finish; //�Ƿ����
	int num;//������
}job[10];

int main()
{
	int num;
	char jname;//������
	int arrive;//����ʱ��	
	int service;//����ʱ��
	int accomplish;//���ʱ��
	scanf("%d",&num);//������
	printf("����������� ����ʱ�� ����ʱ��\n");
	for (int i = 0; i < num; i++)
	{
	
		scanf("%c", &jname);
		job[i].name = jname;
		scanf("%d", &arrive);
		job[i].Tarrive = arrive;
		scanf("%d", &service);
		job[i].Tservice = service;
	}
	display(num);
	return 0;
}
