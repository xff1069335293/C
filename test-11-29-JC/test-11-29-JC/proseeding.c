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

void display(int num)
{
	int input = 0;
	printf("��������������������������������������������������\n");
	printf("��������������������1��FCFS�㷨 ������������������\n");
	printf("��������������������2��SJF�㷨��������������������\n");
	printf("��������������������3��RR�㷨 ��������������������\n");
	printf("��������������������4�����ȼ��㷨 ����������������\n");
	printf("��������������������5���˳� ����������������������\n");
	printf("��������������������������������������������������\n");
	do {
		printf("��ѡ������Ҫ���㷨��");
		scanf("%d",&input);
		switch (input) 
		{
		case 1:
			Arrive_sort(num);
			fcfs(num);
			print(num);
			break;
		case 2:
			Arrive_Short_sort(num);
			sjf(num);
			print(num);
			break;
		case 3:
			RR(num);
			break;
		//case 4:
			//priority(num);
			//break;
		case 0:
			exit;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}
//������ʱ������
void Arrive_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//������ʱ������
void Service_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}

}
void Priority_sort(int num)//�����ȼ���С����
{
	int temp1, temp2, temp3, temp4;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
}
//�������ʱ����ȣ�����ʱ�䰴��С��������
void Arrive_Short_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive >= job[j].Tarrive)
			{
				if (job[i].Tarrive > job[j].Tarrive)
				{
					temp1 = job[j].name;
					job[j].name = job[i].name;
					job[i].name = temp1;
					temp2 = job[j].Tarrive;
					job[j].Tarrive = job[i].Tarrive;
					job[i].Tarrive = temp2;
					temp3 = job[j].Tservice;
					job[j].Tservice = job[i].Tservice;
					job[i].Tservice = temp3;
				}
				else
				{
					if (job[i].Tservice > job[j].Tservice)
					{
						temp1 = job[j].name;
						job[j].name = job[i].name;
						job[i].name = temp1;
						temp2 = job[j].Tarrive;
						job[j].Tarrive = job[i].Tarrive;
						job[i].Tarrive = temp2;
						temp3 = job[j].Tservice;
						job[j].Tservice = job[i].Tservice;
						job[i].Tservice = temp3;
					}
				}
			}
		}
	}
}
void fcfs(int num)//�����ȷ���
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void sjf(int num)//����ҵ����
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
		if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void RR(int num)//RR�㷨
{
	int q;
	printf("������ʱ��Ƭ���ȣ�");
	scanf("%d",&q);
	int flag = 1;//��־�������Ƿ��н���
	int finish_pro = 0;//��ɵĽ�����
	printf("��������  ��ʼʱ��   ����ʱ��  ʣ�����ʱ��  ����ʱ��");
	int time;//��¼��ǰʱ��ʱ��
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//����������û����
		for (int i = c; i < num; i++)
		{
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
			if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//�ý��������
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//δ���������һ��ʱ��Ƭ
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//�ý������
					job[i].Taccomplish = time;
					printf(" job[i].name  job[i].Taccomplish - job[i].Tsurplusjob[i].Tsurplus  job[i].Taccomplish" );
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					printf(" job[i].name time - q  q  job[i].Tsurplus  job[i].Taccomplish ");
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//һ��������ɼ�һ
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//ûִ������û�����������
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
}
void print(int num)
{
	printf("������  ����ʱ��   ����ʱ��  ���ʱ��");

	for (int i = 0; i < num; i++)
	{
		printf(" job[i].name  job[i].Tarrive  job[i].Tservice  job[i].Taccomplish");
	}
}
