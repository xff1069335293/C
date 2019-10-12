
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3   //定义棋盘长度
#define COL 3	//定义棋盘宽度
#define CHESS_NUM 3  //定义棋子个数
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();    //菜单
void test();	//功能选择
void game();	//游戏开始
Tnit_Board(char board[ROW][COL], int row, int col);  //初始化数组
Display_Board(char board[ROW][COL], int row, int col);	//展示棋盘
Player_Move(char board[ROW][COL], int row, int col);	//玩家走
Computer_Move(char board[ROW][COL], int row, int col);	//电脑走
char IsWin(char board[ROW][COL], int row, int col);		//判断输赢