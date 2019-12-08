//sizeof & strlen 相关问题详解
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int arr[10] = { "asdafaf" };
	int* p;
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(arr[1]+1));
	printf("%d\n", sizeof(arr[1+1]));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(int *));
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(*p));
	printf("%d\n", sizeof(*p+1));
	printf("%d\n", sizeof(*p)+1);
	printf("%d\n", sizeof(*(p+1)));
	system("pause");
	return 0;
}