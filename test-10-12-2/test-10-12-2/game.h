
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3   //�������̳���
#define COL 3	//�������̿��
#define CHESS_NUM 3  //�������Ӹ���
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();    //�˵�
void test();	//����ѡ��
void game();	//��Ϸ��ʼ
Tnit_Board(char board[ROW][COL], int row, int col);  //��ʼ������
Display_Board(char board[ROW][COL], int row, int col);	//չʾ����
Player_Move(char board[ROW][COL], int row, int col);	//�����
Computer_Move(char board[ROW][COL], int row, int col);	//������
char IsWin(char board[ROW][COL], int row, int col);		//�ж���Ӯ