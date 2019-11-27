#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>                                                                                                                      
#include <string.h>    
//���� k ���ַ�    
void LeftRotate(char* s, int k) {
	int len = strlen(s);
	char* p;
	char* q;
	for (p = s + k - 1; p >= s; --p) {
		for (q = p; q < p + len - k; ++q) {
			char tmp = *q;
			*q = *(q + 1);
			*(q + 1) = tmp;
		}
	}
}
//���� k ���ַ�    
void RightRotate(char* s, int k) {
	int len = strlen(s);
	char* p;
	char* q;
	for (p = s + len - k; p < s + len; ++p) {
		for (q = p; q > s; --q) {
			char tmp = *q;
			*q = *(q - 1);
			*(q - 1) = tmp;
		}
	}
}
//�ж� s1 �Ƿ�Ϊ s2 ��ת֮����ַ���
int isRotate(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2) {
		return 0;
	}
	char* s;
	int i;
	for (i = 0; i <= len1; ++i) {
		s = s1;
		LeftRotate(s, i);
		if (strcmp(s, s2) == 0) {
			return 1;
		}
		s = s1;
		RightRotate(s, i);
		if (strcmp(s, s2) == 0) {
			return 1;
		}
	}
	return 0;
}
int main() {
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	if (isRotate(s1, s2) == 1) {
		printf("����ת֮���\n");
	}
	else {
		printf("������ת֮��\n");
	}
	system("pause");
	return 0;
}
