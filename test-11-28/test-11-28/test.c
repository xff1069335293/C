//#define _CRT_SECURE_NO_WARNINGS 1
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
///*��д����
//unsigned int  reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//����32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//*/
//#include <stdio.h> 
//#include <math.h> 
//int reverse_bit(unsigned int value)
//{
//	int ret = 0;
//	int bit = 0;
//	int i;
//	for (i = 0; i < 32; i++)
//	{
//		ret = ret << 1; //����һλ������ǰһλ
//		bit = value & 1; //ȡ�����һλ
//		value = value >> 1;//ֵ���ƣ�ȡ��һλ
//		ret = bit | ret; //���һλ����ret
//	}
//	return ret;
//}
//int main()
//{
//	printf("%u\n", reverse_bit(25));
//	system("pause");
//	return 0;
//}
//
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
//#include <stdio.h>
//#include <windows.h>
//
//int main()
//{
//	int a = 25;
//	int b = 5;
//	printf("%d\n", (a&b) + ((a^b) >> 1));
//	system("pause");
//	return 0;
//}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//#include  <stdio.h>
//int main() {
//	int b = 0;
//	int arr[9] = { 0, 0, 2, 2, 3, 3, 4, 4, 1 };
//	for (int i = 0; i < 9; i++) {
//		b = b ^ arr[i];// 1^1=0 0^0=0 1^0=1,���Ե�����������ʣ������
//	}
//
//	printf("%d", b);
//	system("pause");
//}
//
//
//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//	student a am i
//	i ma a tneduts
//	i am a student
#include<stdio.h>
	void  reserve_size(char *pleft, char *pright) {//ת�ú��������ַ���������ת�ã��Լ�ÿ�����ʵ�ת��
	while (pleft < pright) {
		char tep = *pleft;
		*pleft = *pright;
		*pright = tep;
		++pleft;
		--pright;
	}
}
int  strlen(char*arr) {//����ʹ�ÿ⺯�����������б�д�⺯��
	int count = 0;
	while (*arr++) 
	{
		count++;
	}
	return count;
}
void  reserve(char *arr)
{
	int len = strlen(arr);
	//�Ƚ��ַ�������
	reserve_size(arr, arr + len - 1);//����ת�� ���Ϊi ma a tneduts
	char *pstart = arr;//���嵥�ʿ�ͷ
	while (*arr) 
	{
		pstart = arr;//��pstart���¶���
		char *pend = arr;//�տ�ʼ��ʱ��ͷ��ĩβ�غ�
		//�ҵ���ĩβ
		while (' ' != *pend && *pend != '\0') {
			++pend;//�ҵ��ʵ�ĩβ
		}
		reserve_size(pstart, pend - 1);//  ��ÿ�����ʽ���ת��  �ҵ��˵���ĩβ��֮�󵥴ʽ���ת�ã���Ϊend�����ڿո��λ�ã����Դ���pend-1
		arr = pend;//�ѿ�ʼ��λ�����ڷ���pend������Ӱ��pstart

		if (*arr == ' ') {
			++arr;//��Ϊarr���ڿո񴦣��ո񲻲��뽻������������������һ�£����Ǳ����ǿո������\0;�ͻ��޷�ֹͣ������Ҫ��if���жϣ�������ֱ�Ӽ�1
			continue;
		}
	}
}
int main() {

	char arr[] = "student a am i";
	reserve(arr);
	printf("%s", arr);
	system("pause");
}




//	1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//	��Ŀ��
//	����һ���������飬ʵ��һ��������
//	�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//	����ż��λ������ĺ�벿�֡�
//
//#include <stdio.h>  
//#include <stdlib.h>  
//void sort(int *a, int sz)
//{
//	int i = 0;
//	int j = sz - 1;
//	for (i = 0; i != j; i++)
//	{
//		if (a[i] % 2 != 0)
//			continue;
//		else
//		{
//			int t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//			if (a[j] % 2 == 0)
//				j--;
//			i--;
//		}
//
//	}
//}
//
//int main()
//{
//	int a[] = { 1,9,5,6,4,3,1 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i;
//	sort(a, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}
//
//	2.
//	���Ͼ��� 
//	��һ����ά����.
//	�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//	�������������в���һ�������Ƿ���ڡ�
//	ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
//
//
//
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
//
//#include <stdio.h>                                                                                                                      
//#include <string.h>    
//���� k ���ַ�    
//void LeftRotate(char* s, int k) {
//	int len = strlen(s);
//	char* p;
//	char* q;
//	for (p = s + k - 1; p >= s; --p) {
//		for (q = p; q < p + len - k; ++q) {
//			char tmp = *q;
//			*q = *(q + 1);
//			*(q + 1) = tmp;
//		}
//	}
//}
//���� k ���ַ�    
//void RightRotate(char* s, int k) {
//	int len = strlen(s);
//	char* p;
//	char* q;
//	for (p = s + len - k; p < s + len; ++p) {
//		for (q = p; q > s; --q) {
//			char tmp = *q;
//			*q = *(q - 1);
//			*(q - 1) = tmp;
//		}
//	}
//}
//�ж� s1 �Ƿ�Ϊ s2 ��ת֮����ַ���
//int isRotate(char* s1, char* s2) {
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2) {
//		return 0;
//	}
//	char* s;
//	int i;
//	for (i = 0; i <= len1; ++i) {
//		s = s1;
//		LeftRotate(s, i);
//		if (strcmp(s, s2) == 0) {
//			return 1;
//		}
//		s = s1;
//		RightRotate(s, i);
//		if (strcmp(s, s2) == 0) {
//			return 1;
//		}
//	}
//	return 0;
//}
//int main() {
//	char s1[] = "AABCD";
//	char s2[] = "BCDAA";
//	if (isRotate(s1, s2) == 1) {
//		printf("����ת֮���\n");
//	}
//	else {
//		printf("������ת֮��\n");
//	}
//	return 0;
//}
//
//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
//
//#include<stdio.h>
//#include<stdlib.h>
//int fun(int* p, int L) {
//	int m;
//	int count = 0;
//	for (int i = 0; i < L; ++i) {
//		for (int j = 0; j < L; ++j) {
//			if (j == i) {
//				continue;
//			}
//			for (m = 0; m < 32; ++m) {
//				if (((p[i] >> m) & 1) ^ ((p[j] >> m) & 1)) {
//					break;
//				}
//			}
//			if (m == 32) {//˵����һ�����Ͱ�arr[i]��ͬ,������ѭ�������ж���һ����
//				break;
//			}
//			if (j == L - 1) {
//				++count;
//				printf("%d\t", p[i]);
//			}
//		}
//	}
//	return count;
//}
//void main() {
//	int arr[] = { 1,2,3,4,1,9,11,2,3,4,5,5 };
//	int L = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < L; ++i) {
//		printf("%d  ", arr[i]);
//	}
//	printf("\n");
//	printf("\nֻ����һ�ε�����%d��\n", fun(arr, L));
//	system("pause");
//}
//
//
//
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
//#include<stdio.h>
//int main()
//{
//	int money = 20;
//	int sum=0;
//	money ;
//	while (money != 0)
//	{
//		sum += money;
//		money = money / 2;
//		
//	}
//	printf("%d", sum+1);
//	system("pause");
//	return 0;
//
//}
//
//
//3.ģ��ʵ��strcpy
//char* Strcpy(char* des, const char* src) {
//	assert(des != NULL);
//	assert(src != NULL);
//	while (*src != '\0') {
//		*des++ = *src++;
//	}
//	*des = *src;
//	return des;
//}
//
//
//#include <stdio.h>    
//#include <assert.h>  
//int main() {
//	char str1[256] = "asd";
//	char str2[] = "I love you!";
//	Strcpy(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}
//
//4.ģ��ʵ��strcat
//char* Strcat(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* dp = dest;
//	while (*dp != '\0') {
//		++dp;
//	}
//	while (*src != '\0') {
//		*dp++ = *src++;
//	}
//	*dp = *src;
//	return dest;
//}
//
//
//#include <stdio.h>    
//#include <assert.h>  
//int main() {
//	char str1[256] = "I love ";
//	char str2[] = "you";
//	Strcat(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}
//
//1.ʵ��strcpy
//char* Strcpy(char* des, const char* src) {
//	assert(des != NULL);
//	assert(src != NULL);
//	while (*src != '\0') {
//		*des++ = *src++;
//	}
//	*des = *src;
//	return des;
//}
//
//
//#include <stdio.h>    
//#include <assert.h>  
//int main() {
//	char str1[256] = "asd";
//	char str2[] = "I love you!";
//	Strcpy(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}
//
//2.ʵ��strcat
//char* Strcat(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* dp = dest;
//	while (*dp != '\0') {
//		++dp;
//	}
//	while (*src != '\0') {
//		*dp++ = *src++;
//	}
//	*dp = *src;
//	return dest;
//}
//
//
//#include <stdio.h>    
//#include <assert.h>  
//int main() {
//	char str1[256] = "I love ";
//	char str2[] = "you";
//	Strcat(str1, str2);
//	printf("%s\n", str1);
//	return 0;
//}
//
//3.ʵ��strstr
//const char* Strstr(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	������һ�αȽ�ʱ str1 ����ʼλ��    
//	const char* sign = str1;
//	�Ƚ�ʱ str1 ����ʼλ��                                                                                                           
//	const char* restart1 = sign;
//	�Ƚ�ʱ str2 ����ʼλ��    
//	const char* restart2 = str2;
//	while (*restart1 != '\0') {
//		while (*restart1 != '\0' && *restart2 != '\0'
//			&& *restart1 == *restart2) {
//			++restart1;
//			++restart2;
//		}
//		if (*restart2 == '\0') {
//			return sign;
//		}
//		restart2 = str2;
//		++sign;
//		restart1 = sign;
//	}
//	return NULL;
//}
//
//#include <stdio.h>
//#include <assert.h>
//int main() {
//	char str1[] = "I love you!";
//	char str2[] = "love";
//	const char* str = Strstr(str1, str2);
//	printf("%s\n", str);
//	return 0;
//}
//
//4.ʵ��strchr
//const char* Strchr(const char* str, int c) {
//	assert(str != NULL);
//	const char* match = str;
//	while (*match != '\0') {
//		if (*match == c) {
//			return match;
//		}
//		++match;
//	}
//	return NULL;
//}
//
//#include <stdio.h>
//#include <assert.h>
//int main() {
//	char str1[] = "I love you!";
//	const char* str = Strchr(str1, 'l');
//	printf("%s\n", str);
//	return 0;
//}
//
//
//5.ʵ��strcmp
//int Strcmp(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (*str1 == *str2) {
//		if (*str1 == '\0') {
//			return 0;
//		}
//		++str1;
//		++str2;
//	}
//	return *str1 - *str2;
//}
//
//#include <stdio.h>
//#include <assert.h>
//int main() {
//	char str1[] = "love";
//	char str2[] = "move";
//	int point = Strcmp(str1, str2);
//	if (point == 0) {
//		printf("str1 = str2\n");
//	}
//	else if (point > 0) {
//		printf("str1 > str2\n");
//	}
//	else {
//		printf("str1 < str2\n");
//	}
//	return 0;
//}
//
//6.ʵ��memcpy
//void* Memcpy(void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* d = (char*)dest;
//	char* s = (char*)src;
//	while (num) {
//		*d++ = *s++;
//		--num;
//	}
//	return dest;
//}
//#include <stdio.h>
//#include <assert.h>
//struct {
//	char name[40];
//	int age;
//} person, person_cpy;
//char str[] = "My name is sock";
//char str1[] = "sock";                                                                                                              
//Memcpy(str, str1, 5);                                                                                                              
//printf("%s\n", str);                                                                                                               
//Memcpy(person.name, str, strlen(str) + 1);
//person.age = 20;
//Memcpy(&person_cpy, &person, sizeof(person));
//printf("%s   %d\n", person_cpy.name, person_cpy.age);
//
//7.ʵ��memmove
//void* Memmove(void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	����������ڴ��ص�    
//	char* d = (char*)dest + num - 1;
//	char* s = (char*)src + num - 1;
//	while (num) {
//		*d-- = *s--;
//		--num;
//	}
//	return dest;
//}
//#include <stdio.h>
//#include <assert.h>
//int main() {
//	char str[] = "I love sock";
//	char str1[] = "sock";
//	Memmove(str, str1, strlen(str1) + 1);
//	printf("%s\n", str);
//	return 0;
//}
//
//1.ģ��ʵ��strncpy
//char* Strncpy(char* dest, const char* src, size_t n) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (n) {
//		if (*src == NULL) {
//			break;
//		}
//		*dest++ = *src++;
//		--n;
//	}
//	return dest;
//}
//#include <stdio.h>
//#include <assert.h>
//int main() {
//	char string1[256] = { 0 };
//	char string2[] = "I love you foever";
//	Strncpy(string1, string2, 6);
//	printf("%s\n", string1);
//	return 0;
//}
//
//
//2.ģ��ʵ��strncat
//char* Strncat(char* dest, const char* src, size_t n) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest != '\0') {
//		++dest;
//	}
//	while (n) {
//		if (*src == '\0') {
//			break;
//		}
//		*dest++ = *src++;
//		--n;
//	}
//	*dest = '\0';
//	return dest;
//}
//int main() {
//	char string1[256] = "I love";
//	char string2[] = " sock cool";
//	Strncat(string1, string2, 5);
//	printf("%s\n", string1);
//	return 0;
//}
//
//3.ģ��ʵ��strncmp
//int Strncmp(const char* str1, const char* str2, size_t n) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	while (n && *str1++ == *str2++) {
//		if (*str1 == '\0' || *str2 == '\0') {
//			break;
//		}
//		++str1;
//		++str2;
//		--n;
//	}
//	if (n == 0) {
//		return 0;
//	}
//	return *str1 - *str2;
//}
//
//#include <stdio.h>
//#include<stdlib.h>
//#include <assert.h>
//int main() {
//	char string1[] = "socm";
//	char string2[] = "sockcool";
//	int flag = Strncmp(string1, string2, 4);
//	if (flag < 0) {
//		printf("stirng1 < string2\n");
//	}
//	else if (flag > 0) {
//		printf("string1 > string2\n");
//	}
//	else {
//		printf("string1 = string2\n");
//	}
//	printf("%d\n", flag);
//	system("pause");
//	return 0;
//}
