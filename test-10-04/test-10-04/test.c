//1.��ɲ�������Ϸ��
//
//play_game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	printf("�����ֿ�ʼ,������0-100֮������֣�\n");
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (ret == guess) 
//		{
//			printf("��ϲ��¶���\n");
//		}
//		if (ret > guess)
//		{
//			printf("��С�ˣ������²�:\n");
//		}
//		if (ret < guess)
//		{
//			printf("�´��ˣ������²�:\n");
//		}
//	}
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main() {
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do {
//		printf("��ѡ���ܣ�\n 1.������Ϸ\n 0.�˳���Ϸ\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			play_game();
//			break;
//		case 0:
//			printf("��Ϸ�˳�");
//			break;
//		default:
//			printf("�������");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
//binary_search(int arr[],int ch,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (int)((left + right) / 2);
//		if (arr[mid] > ch)
//		{
//			right = mid - 1;
//		}
//	  if (arr[mid] < ch)
//		{
//			left = mid + 1;
//		}
//		if (arr[mid] == ch)
//		
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = {1,2,3,4,5,6,7 ,8,9,10};
//	int ch = 0;
//	scanf("%d", &ch);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int mid = 0;
//	int ret = 0;
//	ret=binary_search(arr, ch, sz);
//	if (ret == -1) 
//	{
//		printf("û�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ����±��ǣ�%d", ret);
//	}
//	system("pause");
//	return 0;
//}
//

//
//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int count = 3;
//	int i = 0;
//	char passward[10] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:\n");
//		//char passward[] = "123456";
//		scanf("%s", passward);
//		if (strcmp(passward, "123456") == 0)
//		{
//			printf("��¼�ɹ���\n");
//			break;
//		}
//		else
//		{
//			count--;
//			printf("��¼ʧ�ܣ��㻹��%d�λ���\n", count);
//		}
//	}
//		if (i == 3) 
//		{
//			printf("��������ʧ�ܣ������Զ��˳�\n");
//		}
//
//		system("pause");
//		return ;
//	}




//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void main() {
//	char ch;
//	printf("�����������ַ���\n");
//	while ((ch=getchar()) != EOF) 
//	{
//		if (ch >= 'a'&& ch <= 'z')
//		{
//			ch = ch - 32;
//			printf("%c\n", ch);
//		}
//		else if (ch >= 'A'&&ch <= 'Z')
//		{
//			ch = ch + 32;
//			printf("%c\n", ch);
//		}
//		else if (ch >= '0'&&ch <= '9')
//		{
//			;
//		}
//		else
//			;
//	}
//	system("pause");
//}