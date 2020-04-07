#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//hoare�汾
void Swap(int* pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void _QuickSort1(int left, int right, int *arr)
{
	int index = right;
	int key = arr[index];
	if (left >= right)
	{
		return;
	}
	//�ұ�key�����
	//�ұ�keyС����
	//����
	while (left < right)
	{
		while (left < right)
		{
			if (arr[left] >= key)
			{
				break;
			}
			++left;
		}

		while (left < right)
		{
			if (arr[right] < key)
			{
				break;
			}
			--right;
		}
		Swap(&arr[left], &arr[right]);	
	}
	Swap(&arr[left], &arr[index]);
	right = index;
	index = left;
	left = 0;
	_QuickSort1(left, index-1, arr); 
	_QuickSort1(index+1,right,arr);
}

//�ڿӷ�
void _QuickSort2(int begin, int end,int * arr)
{
	if (begin >= end)
	{
		return;
	}
	int end1 = end;
	int index = end;
	int key = arr[index];
	
	while (begin <end)
	{	//����key��������ڿ�� ����������
		while (begin < end)
		{
			if (arr[begin] > key)
			{
				arr[index] = arr[begin];
				index = begin;
				break;
			}
			++begin;
		}
		//����keyС�������ڿ�� ����������
		while (begin < end)
		{
			if (arr[end] < key)
			{
				arr[index] = arr[end];
				index = end;
				break;
			}
			--end;
		}
	}
	arr[index] = key;//Ҫ��Key �Żص�����
	_QuickSort2(0, index - 1, arr);//ǰ���
	_QuickSort2(index+1 , end1, arr);//���Σ�һ��Ҫע��end���ˣ���Ҫֱ�Ӵ�end��ֵ����Ȼ����ɺ��Σ�û�б�����
	
}

//ָ�뷨
void _QuickSort3(int begin, int end, int * arr)
{
	if (begin >= end)
	{
		return;
	}
	int key = arr[end];
	int	cur = begin;
	int prev = cur - 1;
	while (cur < end)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[end], &arr[prev]);
	_QuickSort3(0, prev - 1, arr);
	_QuickSort3(prev + 1, end, arr);
}

void QuickSort1(int* arr, int n)
{
	
	//_QuickSort1(0, n - 1, arr);	//hoare��
	//_QuickSort2(0, n - 1, arr);	//�ڿӷ�
	//_QuickSort3(0, n - 1, arr);	//ָ�뷨
}



int Mid(int begin, int end,int* arr)
 {
	int mid = (begin + end) >> 1;
	if (arr[begin] > arr[end])
	{
		if (arr[end] > arr[mid])
		{
			return end;
		}
		else
		{
			if (arr[begin] > arr[mid])
			{
				return mid;
			}
			else
			{
				return begin;
			}
		}
	}
	else
	{
		if (arr[mid] > arr[end])
		{
			return end;
		}
		else
		{
			if (arr[mid] > arr[begin])
			{
				return mid;
			}
			else
			{
				return begin;
			}
		}
	}
	
}

//ָ�뷨
int _QuickSort4(int begin, int end, int * arr)
{
	
	int keyindex = Mid(begin, end, arr);
 	Swap(&arr[keyindex], &arr[end]);
	int key = arr[end];
	int	cur = begin;
	int prev = cur - 1;
	while (cur < end)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[end], &arr[prev]);
	return prev;
}

void QuickSort(int begin,int end,int* arr)		//�Ż�
{
	if (begin >= end)
	{
		return;
	}
	int keyindex = _QuickSort4(begin, end, arr);//����ȡ�з���ѡ���������м���ֵ
	QuickSort(begin, keyindex - 1, arr);
	QuickSort(keyindex + 1, end, arr);
}
	
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1,0,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort( 0, n - 1,arr);
	Print(arr, n);
	system("pause");
	return 0;
}