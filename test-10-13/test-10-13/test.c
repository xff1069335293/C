//
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��


int Mypow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n * Mypow(n, k - 1);
	}
}


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
{
	int n = 2;
	int k = 5;
	int c = Mypow(n, k);
	printf("%d^%d = %d\n", n, k, c);
	return 0;
}




//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 


