#define _CRT_SECURE_NO_WARNINGS 1
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//
//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int k = 0;
	cin >> s >> k;
	k = k % s.size();
	string tmp(s);
	for (int i = 0; i < k; ++i)
	{
		tmp.push_back(s[i]);
	}
	string ret(tmp.begin() + k, tmp.end());
	cout << ret << endl;
	system("pause");
	return 0;
}*/
//#include<iostream>
//#include<string>
//using namespace std; //AABCD CBDAA
//bool Is(string&s1,string&s2)
//{
//	int len1 = s1.size(), len2 = s2.size();
//	int src = 0, dst = 0;
//	while (src < len1)
//	{
//		while (dst < len2&&s1[src] != s2[dst])
//		{
//			++dst;
//		}
//		if (dst == len2)
//		{
//			return false;
//		}
//		while (src < len1&&s1[src] == s2[dst])
//		{
//			++dst;
//			if (dst == len2)
//			{
//				dst = 0;
//			}
//			++src;
//		}
//	}
//	return true;
//}
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		if (Is(s1, s2))
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	system("pause");
//	return 0;
//}

//1.实现strcpy	
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* mystrcpy(char* dst,const char *src)//char * strcpy ( char * destination, const char * source )
{
	assert(dst&&src);
	char* ret = dst;
	/*while (*src != '\0')
	{
		*dst++ = *src++;
	}
	*dst = *src;*/
	//实现链式连接（strlen(strcpy(dst,src))）
	while ((*dst++ = *src++) != '\0');
	return ret;
}
void test1()
{
	char arr1[] = "abcd";
	//char arr1[] = { 'a','b','c','d', '\0'};
	char arr2[1024]  ;
	strcpy(arr2, arr1);
	printf("%s\n", arr2);

	char arr3[1024];
    mystrcpy(arr3,arr1);
	printf("%s\n", arr3);
}
//2.实现strcat
char* mystrcat(char* dst, const char *src)//char * strcpy ( char * destination, const char * source )
{
	assert(dst&&src);
	char * ret = dst;
	while (*dst)
	{
		++dst;
	}
	while (*dst++ = *src++);
	return ret;
}
void test2()
{
	char arr1[30] = "to be or not to";
	char arr2[] = " be!";
	strcat(arr1, arr2);
	printf("%s %d\n", arr1, strlen(arr1));

	char arr4[30] = "to be or not to";
	char arr3[]= " be!";
	mystrcat(arr4, arr3);
	printf("%s %d\n", arr4,strlen(arr4));

}

//3.实现strstr
const char *mystrstr(const char*str1, const char* str2)
{
	assert(str1&&str2);
	while (*str2)
	{
		while (*str1&&*str1 != *str2)
		{
			++str1;
		}
		if (!*str1)
			return NULL;
		const char* tmp1 = str1, *tmp2 = str2;
		while (*str1&&*str2&&*str1 == *str2)
		{
			++str1;
			++str2;
		}
		if (*str2)
			str1 = tmp1 + 1, str2 = tmp2;
		else
			str1=tmp1;
	}
	return str1;
}
void test3()
{
	char arr1[] = "hello world";
	char arr2[]="ld";
	char *ret1 = strstr(arr1, arr2);
	printf("%p %p %p\n", ret1,arr1+9,arr2);

	 char arr3[] = "hello world";
	 char arr4[] = "ld";
	 const char *ret2 = mystrstr(arr3, arr4);
	 printf("%p %p %p\n", ret2,arr3+9,arr4);
 }
//4.实现strchr
 char* mystrchr( char*str, int character) 
{
	 assert(str);
	while (*str)
	{
		if (*str == character)
			return str;
		++str;
	}
	if (*str == character)
		return str;
	return NULL;
}

void test4()
{
	char* ret;
	char arr1[] = "abcdef";
	//char *arr1 = NULL;
	int n1 ='\0';
	ret = strchr(arr1, n1);
	printf("%p %s\n", ret, ret);

	int n2 = '\0';
	char arr2[] = "abcdef";
	//char *arr2 = NULL;
	ret = mystrchr(arr2, n2);
	printf("%p %s\n", ret, ret);
}

//5.实现strcmp
int mystrcmp(const char* str1, const char* str2)//int strcmp ( const char * str1, const char * str2 );
{
	assert(str1&&str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	int max= len1 > len2 ? len1 : len2;
	for (int i = 0; i<max; ++i)
	{
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
		else
				;
	}
	return 0;
	
}
void test5()
{
	const char* arr1 = "appless";
	const char* arr2 = "apple";
	const char* arr3 = "pear";
	int ret = 0;
	ret = strcmp(arr1, arr2); 
	printf("%d\n", ret);

	ret = mystrcmp(arr1, arr2);
	printf("%d\n", ret);
}
//6.实现memcpy
void* mymemcpy(void* dst,const void* src,size_t num)
	//void * memcpy ( void * destination, const void * source, size_t num );
{
	//num是无符号整型，按字节。
	assert(dst&&src);
	unsigned char* pdst = (unsigned char*)dst;
	unsigned char* psrc = (unsigned char*)src;
	int lend = sizeof(pdst) / sizeof(pdst[0]);
	int lens = sizeof(psrc) / sizeof(psrc[0]);
	if ((pdst >= psrc && pdst < psrc + num)
		|| (pdst < psrc&&psrc < pdst + num))
		return NULL;
	else
	{
		for (size_t i = 0; i < num; ++i)
		{
			pdst[i] = psrc[i];
		}
		return pdst;
	}

}
void test6()
{
	//不限定指针类型，按字节拷贝,重叠越界。
	int  arr1[10] = { -1,0,1,4,5};
	int  arr2[5] = { 255,127,8,9,10 };
	memcpy(arr1, arr2, 4);
	mymemcpy(arr1, arr2, 4);
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); ++i)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	char str1[] = "hello xff";	
	char str2[] = { 'w','o','r','l','d' };
	void* ret1 = memcpy(str1, str2, 5);
	printf("%s %p\n", str1, ret1);

	void* ret2 = (char*)mymemcpy(str1, str2, 5);
	printf("%s %p\n", str1, ret2);
}
//7.实现memmove
void* mymemmove(void* dst, void* src, size_t num)
//void * memcpy ( void * destination, const void * source, size_t num );
{
	assert(dst&&src);
	unsigned char* pdst = (unsigned char*)dst;
	unsigned char* psrc = (unsigned char*)src;
	//目的在源端之后，要从后向前拷贝
	if (psrc < pdst&&pdst < psrc + num)
	{
		for (size_t i = num - 1; i >= 0; --i)
		{
			pdst[i] = psrc[i];
		}
		return pdst;
	}
	else
	{
		for (size_t i = 0; i < num; ++i)
		{
			pdst[i] = psrc[i];
		}
		return pdst;
	}
}
void test7()
{
	char str1[] = "hello";
	char str2[] = "world";
	char str3[] = "hello";
	void* ret1 = memmove(str1, str1+2, 10);
	void* ret2 = mymemmove(str3, str3+2, 10);
	printf("%s %p %p\n", str1,str1,ret1);
	printf("%s %p %p\n", str3, str3, ret2);

	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int arr3[5] = { 1,2,3,4,5 };

	void* ret3 = memmove(arr1, arr1 + 2,20 );
	//void* ret4 = mymemmove(arr3+1, arr3, 20);
	void* ret4 = mymemmove(arr3, arr3+2, 20);
	printf("%p %p\n", arr1, ret3);
	printf("%p %p\n", arr3, ret4);
	for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); ++i)
	{
		printf("%d ", arr3[i]);
	}
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	system("pause");
	return 0;
}