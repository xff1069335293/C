#include "game.h"
int main()
{
	srand((unsigned int)time(NULL));//���������������
	int input = 0;
	menu();//�˵�
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (1);
	system("pause");

	return 0;
}
