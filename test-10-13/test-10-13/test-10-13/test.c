//
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��

double Pow(int n, int k)
{
	
	if(k >= 0)
	{
		if (k == 0)
		{
			return	1;
		}
		if (k == 1)
		{
			return n;
		}
		return n * Pow(n, k - 1); 
	}
	else
	{
		return 1.0/(n * Pow(n, -k - 1));
	}


}


#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	int k = 0;
	printf("������n,k��ֵ��\n");
	scanf("%d %d", &n, &k);
	double ret = Pow(n,k);
	printf("%lf", ret);
	system("pause");
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


