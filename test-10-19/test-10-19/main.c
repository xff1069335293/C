#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));//产生随机数生成器
	int input = 0;
	menu();//菜单
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (1);
	system("pause");

	return 0;
}
