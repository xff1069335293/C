#include "game.h"

void menu()
{
	printf("*****************************");
	printf("********* 1.Play  ***********");
	printf("********* 2.exit  ***********");
	printf("*****************************");
}


void game()
{

	int ret = 0;
	init_mine();		//��ʼ��������̺����������
	set_mine();			//����������̲���
	print_mine();		
	printf("\n");
	print_player();		//��ӡ�������


	while (1)//ѭ��ɨ��
	{
		int ret = sweep_mine();//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
		if (count_show_mine() == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
		{
			print_mine();//��ӡ���������
			printf("���Ӯ��\n\n");
			break;
		}
		if (ret)//�ж��Ƿ�ȵ���
		{
			printf("����ը��\t");
			print_mine();//��ӡ���������鿴�׵ķֲ�
			break;
		}print_player();//��ӡ�������
	}
}
void init_mine()//��ʼ����������
{
	int i = 0;
	int j = 0;
	for (int i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			show_mine[i][j] = '*';
			real_mine[i][j] = '0';
		}
	}
}


void print_player()//��ӡ�������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//��ӡ��꣨0--10��
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//�����������
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", show_mine[10][i]);
	}
	printf("\n");
}


void print_mine()//��ӡ���������
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//��ӡ��꣨0--10��
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//��ӡ���꣨1--10��
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", real_mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//��ʼ��ӡ���һ��
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", real_mine[10][i]);
	}
	printf("\n");
}


	void set_mine()			//����������̲���
	{
		int x = 0;
		int y = 0;
		int count = COUNT;//������
		while (count)//�ײ��������ѭ��
		{
			int x = rand() % 10 + 1;
			int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
			if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
			{
				real_mine[x][y] = '1';
				count--;
			}
		}
	}

	int count_mine(int x, int y)
	{
		int count = 0;
		if (real_mine[x - 1][y - 1] == '1')
			count++;
		if (real_mine[x - 1][y] == '1')
			count++;
		if (real_mine[x - 1][y + 1] == '1')
			count++;
		if (real_mine[x][y - 1] == '1')
			count++;
		if (real_mine[x][y + 1] == '1')
			count++;
		if (real_mine[x + 1][y - 1] == '1')
			count++;
		if (real_mine[x + 1][y] == '1')
			count++;
		if (real_mine[x + 1][y + 1] == '1')
			count++;
		return count;
	}

	int sweep_mine()		//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
	{
		int x = 0;
		int y = 0;
		int count = 0;
		printf("��������ɨ��\n");
		scanf("%d%d", &x, &y);//ֻ������1��10
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//�ж����������Ƿ��������������������
		{
			if (real_mine[x][y] == '0')//û�ȵ���
			{
				char ch = count_mine(x, y);
				show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
				open_mine(x, y);
				if (count_show_mine() == COUNT)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
				{
					print_mine();
					printf("���Ӯ��\n\n");
					return 0;
				}
			}
			else if (real_mine[x][y] == '1')//�ȵ���
			{
				return 1;
			}

		}
		else
		{
			printf("���������������\n");
		}
		return 0;//û�ȵ���
	}

	int count_show_mine()//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
	{
		int count = 0;
		int i = 0;
		int j = 0;
		for (i = 1; i <= row - 2; i++)
		{
			for (j = 1; j <= col - 2; j++)
			{
				if (show_mine[i][j] == '*')
				{
					count++;
				}
			}

		}
		return count;
	}



	