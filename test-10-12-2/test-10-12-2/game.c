#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("******  1.play 0.exit ******\n");
	printf("****************************\n");
}

void test()
{
	int input = 0;
	printf("��ѡ���Ƿ������Ϸ��\n");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��Ϸ�˳���\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);
}

Tnit_Board(char board[ROW][COL],int row,int col)	//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			board[i][j] = ' ';
		}
		printf("\n");
	}
}
Display_Board(char board[ROW][COL], int row, int col)	//��ʾ����
{
	int i = 0;
	int j = 0;

	for (j = 0; j < row; j++)
	{
		printf("---");
		printf("|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]); //���ݲ�����ʱ�򴫵ݵ��Ǿ����ֵ��ROW COL���´���
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			printf("|");
		}
		printf("\n");
	}
}

Player_Move(char board[ROW][COL], int row, int col)	//�����
{
	int x, y;
	while (1)
	{	printf("������Ҫ�ߵ�����\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < row+1 && y>0 && y < col+1)  //ʵ��������0-2
		{
			if (board[x - 1][y - 1] == ' ') 
			{
				board[x - 1][y - 1] = '*';
				break;
			
			}
			else
			{
				printf("��λ�ñ�������\n");
			}
		}
		else
		{

			printf("����������������룺\n");
		}
	} 
}

Computer_Move(char board[ROW][COL], int row, int col)	//������
{	
	int x, y;
	while (1)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1; //����1---ROW����
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
		else
		{
			continue;
		}

	}

}

char IsWin(char board[ROW][COL], int row, int col)		//�ж���Ӯ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];		//�ж������
			break;
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
			break;					//�ж������
		}

	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')			//�ж϶Խ���
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	for (i = 0; i < row; i++)		//�ж��Ƿ��п�λ��ƽ�ֵ����
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}

		}
	}
	return 1;
}



void game()
{
	char board[ROW][COL] = { 0 };
	Tnit_Board(board, ROW, COL); //��ʼ������
	Display_Board(board, ROW, COL);//��ӡ����
	while (1)
	{
		printf("��һغϣ�\n");
		Player_Move(board, ROW, COL);
		Display_Board(board, ROW, COL);//��ӡ����
		printf("���Իغϣ�\n");
		Computer_Move(board, ROW, COL);
		Display_Board(board, ROW, COL);//��ӡ����
		int ret = IsWin(board, ROW, COL);
		if (ret == 1)
		{
			printf("ƽ�ֽ���\n");
			break;
		}
		if (ret == '*')
		{
			printf("���ʤ��\n");
			break;
		}
		if (ret == '#')
		{
			printf("����ʤ��\n"); 
			break;
		}
		  //����0��ʱ����������
	}
	menu();
	
}

