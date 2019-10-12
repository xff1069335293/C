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
	printf("请选择是否进入游戏：\n");
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("游戏退出：\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
}

Tnit_Board(char board[ROW][COL],int row,int col)	//初始化数组
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
Display_Board(char board[ROW][COL], int row, int col)	//显示棋盘
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
			printf(" %c ", board[i][j]); //传递参数的时候传递的是具体的值，ROW COL导致错误
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

Player_Move(char board[ROW][COL], int row, int col)	//玩家走
{
	int x, y;
	while (1)
	{	printf("请输入要走的坐标\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < row+1 && y>0 && y < col+1)  //实际坐标是0-2
		{
			if (board[x - 1][y - 1] == ' ') 
			{
				board[x - 1][y - 1] = '*';
				break;
			
			}
			else
			{
				printf("该位置被有棋子\n");
			}
		}
		else
		{

			printf("输入错误请重新输入：\n");
		}
	} 
}

Computer_Move(char board[ROW][COL], int row, int col)	//电脑走
{	
	int x, y;
	while (1)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1; //产生1---ROW的数
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

char IsWin(char board[ROW][COL], int row, int col)		//判断输赢
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];		//判断行相等
			break;
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
			break;					//判断列相等
		}

	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')			//判断对角线
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	for (i = 0; i < row; i++)		//判断是否还有空位，平局的情况
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
	Tnit_Board(board, ROW, COL); //初始化棋盘
	Display_Board(board, ROW, COL);//打印棋盘
	while (1)
	{
		printf("玩家回合：\n");
		Player_Move(board, ROW, COL);
		Display_Board(board, ROW, COL);//打印棋盘
		printf("电脑回合：\n");
		Computer_Move(board, ROW, COL);
		Display_Board(board, ROW, COL);//打印棋盘
		int ret = IsWin(board, ROW, COL);
		if (ret == 1)
		{
			printf("平局结束\n");
			break;
		}
		if (ret == '*')
		{
			printf("玩家胜利\n");
			break;
		}
		if (ret == '#')
		{
			printf("电脑胜利\n"); 
			break;
		}
		  //返回0的时候会继续下棋
	}
	menu();
	
}

