//ģ��ʵ��strchr
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
const char* Mystrchr(const char* dst, const char str) {
	assert(dst != NULL);
	while (*dst != '\0') {//ѭ��������ָ�벻ָ���ַ�����β
		if (*dst == str) {//������,���ؿ�ʼ���ҵ�λ��
			return dst;
		}
		dst++;//ѭ�������Ӽ�
	}
	return NULL;
}
int main() 
{
	char buf[] = "hello world";
	char* p = Mystrchr(buf, 'o');
	printf("%s", p);
	system("pause");
	return 0;
}
