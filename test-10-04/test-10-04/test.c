//1.��ɲ�������Ϸ��
//

//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main() {
//	int ch;
//	scanf("%d", &ch);
//	
//
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

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int ch=0;
	int count = 3;
	scanf("%d", &ch);
	int passward = "123456";
	while (count > 0) 
	{
		if (passward == ch)
		{
			printf("��¼�ɹ���/n");
		}
		else
		{
			count--;
			printf("��¼ʧ�ܣ��㻹��%d�λ���", count);
			continue;
		}
	}

	system("pause");
	return 0;
}




//4.��дһ�����򣬿���һֱ���ռ����ַ���
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void main() {
//	char ch;
//	void	getchar(ch);
//	while (ch == EOF) {
//		if ((ch > 0) && (ch < 9))
//		{
//			;
//		}
//		if ((ch > 'a') && (ch < 'z')) {
//			putchar(ch + 32);
//		}
//		if ((ch >= 'A') && (ch = < 'Z')) {
//			putchar(ch - 32);
//		}
//	}
//
//	system("pause");
//}