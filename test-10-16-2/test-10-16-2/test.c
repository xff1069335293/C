//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Reverse_string(char *str) {
	if (*(++str) != '\0')
	{
		Reverse_string(str);
	}
	printf("%c", *(str - 1));
}
int main() {
	char a[] = "HelloWorld";
	Reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}