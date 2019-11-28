//#define _CRT_SECURE_NO_WARNINGS 1
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
///*编写函数
//unsigned int  reverse_bit(unsigned int value);
//这个函数的返回值吧value的二进制位模式从左到右翻转后的值。
//如在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
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
//		ret = ret << 1; //左移一位，保存前一位
//		bit = value & 1; //取出最后一位
//		value = value >> 1;//值右移，取下一位
//		ret = bit | ret; //最后一位赋给ret
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
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
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
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//#include  <stdio.h>
//int main() {
//	int b = 0;
//	int arr[9] = { 0, 0, 2, 2, 3, 3, 4, 4, 1 };
//	for (int i = 0; i < 9; i++) {
//		b = b ^ arr[i];// 1^1=0 0^0=0 1^0=1,所以单独的数最后就剩下来了
//	}
//
//	printf("%d", b);
//	system("pause");
//}
//
//
//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//	student a am i
//	i ma a tneduts
//	i am a student
#include<stdio.h>
	void  reserve_size(char *pleft, char *pright) {//转置函数参与字符串的整体转置，以及每个单词的转置
	while (pleft < pright) {
		char tep = *pleft;
		*pleft = *pright;
		*pright = tep;
		++pleft;
		--pright;
	}
}
int  strlen(char*arr) {//不能使用库函数，所以自行编写库函数
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
	//先将字符串逆置
	reserve_size(arr, arr + len - 1);//整体转置 结果为i ma a tneduts
	char *pstart = arr;//定义单词开头
	while (*arr) 
	{
		pstart = arr;//给pstart重新定义
		char *pend = arr;//刚开始的时候开头和末尾重合
		//找单词末尾
		while (' ' != *pend && *pend != '\0') {
			++pend;//找单词的末尾
		}
		reserve_size(pstart, pend - 1);//  将每个单词进行转置  找到了单词末尾，之后单词进行转置，因为end现在在空格的位置，所以传入pend-1
		arr = pend;//把开始的位置现在放在pend处，来影响pstart

		if (*arr == ' ') {
			++arr;//因为arr是在空格处，空格不参与交换，所以让他朝后走一下，但是必须是空格，如果是\0;就会无法停止，所以要用if来判断，而不是直接加1
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




//	1.调整数组使奇数全部都位于偶数前面。
//
//	题目：
//	输入一个整数数组，实现一个函数，
//	来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//	所有偶数位于数组的后半部分。
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
//	杨氏矩阵 
//	有一个二维数组.
//	数组的每行从左到右是递增的，每列从上到下是递增的.
//	在这样的数组中查找一个数字是否存在。
//	时间复杂度小于O(N);
//
//数组：
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
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
//
//#include <stdio.h>                                                                                                                      
//#include <string.h>    
//左旋 k 个字符    
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
//右旋 k 个字符    
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
//判断 s1 是否为 s2 旋转之后的字符串
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
//		printf("是旋转之后的\n");
//	}
//	else {
//		printf("不是旋转之后\n");
//	}
//	return 0;
//}
//
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
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
//			if (m == 32) {//说明有一个数和啊arr[i]相同,则跳出循环，再判断下一个数
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
//	printf("\n只出现一次的数有%d个\n", fun(arr, L));
//	system("pause");
//}
//
//
//
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
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
//3.模拟实现strcpy
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
//4.模拟实现strcat
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
//1.实现strcpy
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
//2.实现strcat
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
//3.实现strstr
//const char* Strstr(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	保存下一次比较时 str1 的起始位置    
//	const char* sign = str1;
//	比较时 str1 的起始位置                                                                                                           
//	const char* restart1 = sign;
//	比较时 str2 的起始位置    
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
//4.实现strchr
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
//5.实现strcmp
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
//6.实现memcpy
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
//7.实现memmove
//void* Memmove(void* dest, const void* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	倒序拷入避免内存重叠    
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
//1.模拟实现strncpy
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
//2.模拟实现strncat
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
//3.模拟实现strncmp
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
