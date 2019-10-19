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
	init_mine();		//初始化玩家棋盘和设计者棋盘
	set_mine();			//给设计者棋盘布雷
	print_mine();		
	printf("\n");
	print_player();		//打印玩家棋盘


	while (1)//循环扫雷
	{
		int ret = sweep_mine();//扫雷,踩到雷返回1，没有踩到雷返回0
		if (count_show_mine() == COUNT)//若玩家棋盘的'*'个数为雷数时，扫雷完成，游戏胜利
		{
			print_mine();//打印设计者棋盘
			printf("玩家赢！\n\n");
			break;
		}
		if (ret)//判断是否踩到雷
		{
			printf("被雷炸死\t");
			print_mine();//打印设计者雷阵查看雷的分布
			break;
		}print_player();//打印玩家棋盘
	}
}
void init_mine()//初始化两个雷阵
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


void print_player()//打印玩家棋盘
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//打印横标（0--10）
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//打印竖标（1--10）
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//玩家棋盘数组
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", show_mine[10][i]);
	}
	printf("\n");
}


void print_mine()//打印设计者棋盘
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//打印横标（0--10）
	}
	printf("\n");
	for (i = 1; i < row - 2; i++)//打印竖标（1--10）
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", real_mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", real_mine[10][i]);
	}
	printf("\n");
}


	void set_mine()			//给设计者棋盘布雷
	{
		int x = 0;
		int y = 0;
		int count = COUNT;//雷总数
		while (count)//雷布完后跳出循环
		{
			int x = rand() % 10 + 1;
			int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
			if (real_mine[x][y] == '0')//找不是雷的地方布雷
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

	int sweep_mine()		//扫雷函数，踩到雷返回1，没有踩到雷返回0
	{
		int x = 0;
		int y = 0;
		int count = 0;
		printf("输入坐标扫雷\n");
		scanf("%d%d", &x, &y);//只能输入1到10
		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10))//判断输入坐标是否有误，输入错误重新输入
		{
			if (real_mine[x][y] == '0')//没踩到雷
			{
				char ch = count_mine(x, y);
				show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				open_mine(x, y);
				if (count_show_mine() == COUNT)//判断剩余未知区域的个数，个数为雷数时玩家赢
				{
					print_mine();
					printf("玩家赢！\n\n");
					return 0;
				}
			}
			else if (real_mine[x][y] == '1')//踩到雷
			{
				return 1;
			}

		}
		else
		{
			printf("输入错误重新输入\n");
		}
		return 0;//没踩到雷
	}

	int count_show_mine()//判断剩余未知区域的个数，个数为雷数时玩家赢
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



	