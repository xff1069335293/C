#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void my_strcpy(char* a, char* b)	//÷∏’Î µœ÷
{
	while (*a++ = *b++)
	{
		/**a = *b;
		a++;	
		b++;*/
	}
	*a = '\0';
}



int main()
{
	char p1[20] = "hello";
	char p2[20] = "wrold";
	my_strcpy(p1,p2);
	printf("%s", p1);
	system("pause");
	return 0;
}